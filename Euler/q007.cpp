# include <bits/stdc++.h>
using namespace std;

int main()
	{
	bool seive[1000001]={false};
	int count=0;
	long int temp;
	seive[0]=1;
	seive[1]=1;
	for (long int i=2;i<1000001;i++)
		{
		if (seive[i]==false)
			{
			for(long int j=i*i;j<1000001;j=j+i)
				{
				seive[j]=true;
				}
			count++;
			cout<<count<<"\t"<<i<<endl;
			}
		if (count==10001)
			{	
			cout<<i;
			break;
			}
		}
	return 0;
	}