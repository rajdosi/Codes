# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int dp[100][50],i,j;
	int final[60]={0};
	char inp[50];
	int carry=0;
	for (i=0;i<100;i++)
		{
		for(j=0;j<50;j++)
			{
			cin>>inp[j];
			dp[i][j]=inp[j]-48;
			}
		getchar();
		}
	cout<<endl<<endl<<endl;
	for (j=49;j>=0;j--)
		{
		for (i=0;i<100;i++)
			{	
			final[j+10]=final[j+10]+dp[i][j];
			}
		final[j+10]=final[j+10]+carry;
		carry=final[j+10]/10;
		final[j+10]=final[j+10]%10;
		}
	j=9;
	while(carry!=0)
		{
		final[j]=carry%10;
		carry=carry/10;
		//cout<<final[j];
		j--;
		}	
	cout<<endl;
	for(i=0;i<60;i++)
	 	cout<<final[i];
	return 0;
	}