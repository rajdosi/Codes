# include <bits/stdc++.h>
using namespace std;

int *modsei=new int[1000001];

int main()
	{
	bool NF=true;
	modsei[0]=modsei[1]=0;
	for (int i=2;i<1000;i++)
		{
		if (modsei[i]==0)
			{
			modsei[i]=1;
			for (long int j=i+i;j<1000001;j=j+i)
				modsei[j]++;
			}	
		}
	long int i=30;
	while(NF==true)
		{
		i++;
		//cout<<i<<"\t"<<modsei[i]<<"\n";
		if (modsei[i]>=4 && modsei[i+1]>=4 && modsei[i+2]>=4 && modsei[i+3]>=4)
			{
			cout<<endl;	
			cout<<i;
			NF=false;	
			}	
		}
	cout<<endl;
	return 0;
	}