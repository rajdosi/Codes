# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int n;
	cin>>n;
	int inp[n][n];
	long long dp[n][n]={0};
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++)
			cin>>inp[i][j];
	for (int i=0;i<n;i++)
		dp[n-1][i]=inp[n-1][i];
	for (int i=n-2;i>=0;i--)
		{
		for (int j=0;j<=i;j++) 
			{
			dp[i][j]=max(dp[i+1][j]+inp[i][j],dp[i+1][j+1]+inp[i][j]);	
			}
		}
	cout<<dp[0][0];
	return 0;
	}