# include <bits/stdc++.h>
using namespace std;
long long m=10000000000;

int main()
	{
	long long sum=0;
	for (int i=1;i<1000;i++)
		{
		if (i%10!=0)
			{
			long long temp=1;
			for (int j=i;j>=1;j--)
				{
				temp=temp*i;
				temp=temp%m;
				} 
			sum=sum+temp;
			sum=sum%m;
			}
		}	
	cout<<sum;
	cout<<endl; 	
	return 0;
	}