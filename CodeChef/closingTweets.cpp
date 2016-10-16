# include <bits/stdc++.h>
using namespace std;

long stolo(string str) {
	long longVal = str[str.length()-1] - '0';
	for (int i=str.length()-2;i>=0;i--)
		longVal += ((str[i] - '0')*pow(10,str.length()-i-1));
	return longVal;
}

int main() {
	long tweets,clicks;
	cin>>tweets>>clicks;
	set<long> openClicks;
	cin.ignore();
	while (clicks--) {
		string str;
		getline(cin,str);
		if (!str.compare("CLOSEALL")) {
			openClicks.clear();
		}
		else {
			long num = stolo(str.substr(6));
			if (openClicks.find(num) != openClicks.end()) {
				openClicks.erase(num);
			}
			else {
				openClicks.insert(num);
			}
		}
			
		cout<<openClicks.size()<<endl;
	}

	return 0;
}