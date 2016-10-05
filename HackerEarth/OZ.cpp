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
		long int b=0,e=s.length()-1;
		long long m1=0,m2=0;
		while(b<e)
			{
			while (s[b]=='O')
				b++;
			while (s[e]=='Z')				
				e--;
			if (b<e)
				{
				s[b]='Z';
				s[e]='O';
				m1=m1+(e-b);
				b++;
				e--;
				}
			}
		b=0,e=s.length()-1;
		while(b<e)
			{
			while (s[b]=='Z')
				b++;
			while (s[e]=='O')				
				e--;
			if (b<e)
				{
				s[b]='O';
				s[e]='Z';
				m2=m2+(e-b);
				b++;
				e--;
				}
			}
		if (m1>m2)
			cout<<m2<<endl;
		else
			cout<<m1<<endl;
		}
	return 0;
	}