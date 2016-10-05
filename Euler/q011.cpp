# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int i,j;
	long int grid[20][20];
	long int smax=LONG_MIN,pro;
	for(i=0;i<20;i++)
		{
		for (j=0;j<20;j++)
			cin>>grid[i][j];
		}
	for (i=0;i<17;i++)
		{
		for (j=0;j<17;j++)
			{
			pro=max(grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3],grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
			pro=max(pro,grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
			if (pro>smax)
				smax=pro;
			}
		}
	for (int i=3;i<20;i++)
		{
		for (int j=0;j<17;j++)
			{
			pro=max(pro,grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3]);
			if(pro>smax)
				smax=pro;
			}
		}
	cout<<smax;
	return 0;
	}