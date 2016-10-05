# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long dp[8][201]={0};
	int val[8]={1,2,5,10,20,50,100,200};
	for (int i=0;i<=200;i++)
		dp[0][i]=1;
	for (int i=1;i<8;i++)
		{
		for (int j=0;j<=val[i];j++)
			{
			dp[i][j]=dp[i-1][j];
			}
		for (int j=val[i];j<=200;j++)
			{
			dp[i][j]=dp[i-1][j];
			dp[i][j]=dp[i][j]+(dp[i][j-val[i]]);
			}
		}
	cout<<dp[7][200];	
	return 0;	
	}