# include<bits/stdc++.h>
using namespace std;

int main()
	{
	int n,i,j;
	cin>>n;
	long long grid[n+1][n+1]={0};
	for (i=0;i<n+1;i++)
		{
			grid[i][0]=1;
			grid[0][i]=1;
		}
	for (i=1;i<n+1;i++)
		{
		for (j=1;j<n+1;j++)
			{
			grid[i][j]=grid[i-1][j]+grid[i][j-1];
			}
		}	
	cout<<grid[n][n];
	return 0;
	}