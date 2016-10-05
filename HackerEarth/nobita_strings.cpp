# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int t;
	cin>>t;
	char a;
	cin.get(a);
	string str;
	while (t--)
		{
		vector <string> V;
		getline(cin,str);
		istringstream iss(str);
		string s;
		while(iss>>s)	
			V.push_back(s);
		for (vector <string>::reverse_iterator it=V.rbegin();it!=V.rend();it++)
			cout<<*it<<" ";
		cout<<endl;
		}	
	return 0;
	}