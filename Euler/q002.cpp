# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long dp[1001]={0},sum=0;
	int i;
	dp[0]=1;
	dp[1]=2;
	sum=sum+2;
	for (i=2;;i++)
		{
		dp[i]=dp[i-1]+dp[i-2];
		if ((i-1)%3==0)
			sum=sum+dp[i];
		if (dp[i]>=4000000)
			break;
		}
	cout<<sum;
	return 0;
	}