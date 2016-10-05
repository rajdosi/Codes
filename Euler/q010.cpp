# include <bits/stdc++.h>
using namespace std;

int main()
	{
	bool *seive=new bool[2000000];
	long long sum=0;
	seive[0]=1;
	seive[1]=1;
	for (long int i=0;i<2000000;i++)
		{
		if(seive[i]==false)
			{
			sum=sum+i;
			for (long int j=i*i;j<2000000;j=j+i)
				{
				seive[j]=1;
				}
			}
		}
	cout<<sum;
	return 0;
	}