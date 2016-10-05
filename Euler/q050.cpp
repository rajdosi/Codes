# include <bits/stdc++.h>
using namespace std;

vector <long int> V;

bool *seive=new bool[1000001];

int main()
	{
	seive[1]=seive[0]=1;
	for (long int i=2;i<1000001;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<1000001;j=j+i)
				seive[j]=true;
			V.push_back(i);
			}
		}
	long int *dp=new long int[V.size()];
	long int size;
	for (long int i=0;i<V.size();i++)
		{
		long int count=i;
		while(count!=(i+21))
			{
			dp[i]=dp[i]+V[count];
			count++;	
			}	
		if (dp[i]>1000000)
			{
			dp[i]=0;	
			size=i;
			break;
			}
		}
	int max=INT_MIN;
	long int index;
	int c=21;
	for (int k=0;k<size-1;k++)
		{
		for (long int i=0,j=c;(dp[i]+V[j])<=1000000;i++,j++)
			{
			dp[i]=dp[i]+V[j];	
			if (seive[dp[i]]==0)
				{	
				if (max<(j))
					{
					max=c+1;
					index=i;
					}	
				}
			}
		c++;
		}
	cout<<dp[index]<<"\t"<<max<<"\n";
	cout<<endl;
	return 0;
	}