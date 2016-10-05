# include <bits/stdc++.h>
using namespace std;

int countSubString(const string& str,const string& subStr) {
	int count=0;
	for (size_t offset=str.find(subStr); offset != std::string::npos;offset = str.find(subStr,offset + subStr.length())){
		count++;
	}
	return count;
}

int main (){
	int t;
	string suvo = "SUVO";
	string suvojit= "SUVOJIT";
	cin>>t;

	while (t--) {
		string str;
		cin>>str;
		
		int s1=countSubString(str,suvo);
		int s2=countSubString(str,suvojit);
		
		cout<<"SUVO = "<<s1-s2<<", SUVOJIT = "<<s2<<endl;	
	}
	return 0;
}