# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while (t--) {
		string str;
		cin>>str;
		map<char,long> charToFreqMap;

		for (int i=0;i<str.length();i++){
			if(charToFreqMap.find(str[i]) == charToFreqMap.end())
				charToFreqMap.insert(pair<char,long>(str[i],1));
			else
				charToFreqMap[str[i]] += 1; 
		}

		bool flag = true;

		for (map<char,long>::iterator it=charToFreqMap.begin(); it!=charToFreqMap.end(); it++)
			if (it->second % 2 != 0){
				flag = false;
				// cout<<it->first<<"\t"<<it->second<<endl;
			}

		if (flag)
			cout<<"1"<<endl;
		else
			cout<<"-1"<<endl;
	}

	return 0;
}