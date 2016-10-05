# include <bits/stdc++.h>
using namespace std;

long long check(long long a)
	{
	if (a>1000000007)
		a=a%1000000007;
	return a;
	}

int main()
	{
	long long freq[128]={0};
	int n,a;
	cin>>n;
	for (int i=0;i<n;i++)
		{
		cin>>a;
		long long temp[128]={0};
		for (int j=0;j<128;j++)
			{
			if (freq[j]!=0)
				{
				long long m=j^a;
				temp[m]+=freq[j];
				temp[m]=check(temp[m]);
				}
			}
		for (int j=0;j<128;j++)
			{
			freq[j]+=temp[j];	
			freq[j]=check(freq[j]);
			}
		freq[a]++;
		freq[a]=check(freq[a]);
		}
	long long sum=0;
	for (int i=0;i<128;i++)
		{
		long long prod=(freq[i]*(freq[i]-1))/2;
		prod=check(prod);
		sum=sum+prod;
		sum=check(sum);
		}
	cout<<sum;
	return 0;
	} 