# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long int a=1002001;
	long long sum=1;
	long int n=2,m=8;
	for (long int i=3;i<=a;i=i+n)
		{
		int x=4;
		while (x--)
			{
			sum=sum+i;
			i=i+n;
			}
		i=i-n;
		n=n+2;
		m=m*2;
		}
	cout<<sum;
	return 0;
	}