# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long dp[13][1000]={0},max=LLONG_MIN;
	char inp[1000];
	for (int i=0;i<1000;i++)
		{
		cin>>inp[i];
		dp[0][i]=inp[i]-48;
		}
	// for (int i=0;i<1000;i++)
		// cout<<dp[0][i]<<"\t";
	for (int i=1;i<13;i++)
		{
		for(int j=i;j<1000;j++)
			{
			dp[i][j]=dp[i-1][j-1]*dp[0][j];
			//cout<<dp[i][j]<<"\t";
			}
		//cout<<endl;
		}
	for (int i=12;i<1000;i++)
		{
		if (dp[12][i]>max)	
			max=dp[12][i];
		}
	cout<<max;
	return 0;
	}