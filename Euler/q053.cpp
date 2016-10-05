# include <bits/stdc++.h>
using namespace std;


int main()
	{
	long long pascal[101][101]={0};
	bool mapp[101][101]={0};
	int count=0;
	for (int i=1;i<101;i++)
		{
		for (int j=0;j<=i;j++)
			{
			if (j==i || j==0)
				pascal[i][j]=1;
			else
				{
				pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];			
				if (pascal[i][j]>1000000 || mapp[i-1][j-1]==1 || mapp[i-1][j]==1 )
					{
					mapp[i][j]=1;
					count++;
					}
				}	
			}
		}
	cout<<count;
	cout<<endl;
	return 0;
	}