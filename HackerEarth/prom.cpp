# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int t;
	cin>>t;
	while(t--)
		{
		int m,n;
		cin>>m>>n;
		int *boy=new int[m];
		int *girl=new int[n];
		for (int i=0;i<m;i++)
			cin>>boy[i];
		for (int i=0;i<n;i++)
			cin>>girl[i];
		if (n<m)
			{
			cout<<"NO"<<endl;
			}
		else
			{
			sort(boy,boy+m);
			sort(girl,girl+n);
			int flag=0;
			for (int i=0;i<m;i++)
				{
				if (boy[i]<=girl[i])
					{
					cout<<"NO"<<endl;
					flag=1;
					break;
					}
				}
			if (flag==0)
				cout<<"YES"<<endl;
			}
		}
	return 0;
	}