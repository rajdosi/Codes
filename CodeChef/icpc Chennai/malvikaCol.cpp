# include <bits/stdc++.h>
using namespace std;

int main()
	{
		int t;
		cin>>t;
		while(t--)
			{
				string s;
				cin>>s;
				int a=0,b=0;
				for (int i=0;i<s.length();i++)
				{
					if (s[i]=='a')
						a++;
					else
						b++;
				}
				if (b<a)
					cout<<b;
				else
					cout<<a;
			}
	return 0;
	}