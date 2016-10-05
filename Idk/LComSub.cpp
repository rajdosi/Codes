# include <bits/stdc++.h>
using namespace std;

int main()
	{
	string a,b;
	cin>>a>>b;
	int n=a.length(),m=b.length();
	int dp[n+1][m+1]={0};
	for (int i=0;i<=n;i++)
		{
		for (int j=0;j<=m;j++)
			{
			if (i==0 || j==0)
				dp[i][j]=0;
			else if (a[i-1]==a[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	cout<<dp[n][m]<<endl;	
	return 0;
	}

/* For printing longest common subsequence start from the last row and column and try to reach the top 
Traverse the 2D array starting from L[m][n]. Do following for every cell L[i][j]
a) If characters (in X and Y) corresponding to L[i][j] are same (Or X[i-1] == Y[j-1]), then include this character as part of LCS.
b) Else compare values of L[i-1][j] and L[i][j-1] and go in direction of greater value.*/