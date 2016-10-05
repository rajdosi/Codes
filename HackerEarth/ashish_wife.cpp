# include <bits/stdc++.h>
using namespace std;

vector <long long> V;

int main()
	{
	long long t;
	cin>>t;
	while(t--)
		{
		long long n,k;
		cin>>n>>k;
		for (int i=0;i<n;i++)
			{
			long long p;
			cin>>p;
			// if((find(V.begin(),V.end(),p))==V.end())
			// 	V.push_back(p);
			}	
		if (n==k)
			cout<<"Perfect husband"<<endl;
		else if (n<k)
			cout<<"Bad husband"<<endl;
		else if (n>k)
			cout<<"Lame husband"<<endl;
		}
	return 0;	
	}