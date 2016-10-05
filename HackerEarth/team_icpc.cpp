# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int t;
	cin>>t;
	while(t--)
		{
		int n,k;
		cin>>n>>k;
		long int los[100]={0};
		string s;
		for (int i=0;i<n;i++)
			{
			cin>>s;
			los[s.length()]++;
			}
		bool flag=0;
		for (int i=0;i<100;i++)
			{
			if (los[i]%k!=0)
				{
				flag=1;
				cout<<"Not possible"<<endl;
				break;
				}
			}
		if (flag==0)
			cout<<"Possible"<<endl;
		}
	return 0;
	}