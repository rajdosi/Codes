# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int initial[19]={3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
	int sec[]={6,6,5,5,5,7,6,6};
	int dp[10][101]={0};
	long long max=0;
	for (int i=1;i<20;i++)
		{
		dp[0][i]=initial[i-1];
		}
	for (int i=20;i<100;i=i+10)
		{
		dp[0][i]=sec[(i/10)-2];
		for (int j=0;j<9;j++)
			{
			dp[0][i+j+1]=sec[(i/10)-2]+initial[j];
			}
		}
	dp[0][100]=10;
	for (int i=1;i<10;i++)
		{
		for (int j=1;j<100;j++)	
			{
			dp[i][j]=dp[i-1][100]+dp[i-1][j]+3-dp[i-2][100];
			if (i!=1)
				dp[i][j]-=3;
			}
		dp[i][100]=7+initial[i];
		}
	dp[9][100]=11;
	for (int i=0;i<10;i++)
		{
		for (int j=1;j<101;j++)
			{
			cout<<dp[i][j]<<"\t";
			max=max+dp[i][j];
			if (j%10==0)
				cout<<endl;
			}
		}
	cout<<endl<<endl<<max<<endl;
	return 0;
	}