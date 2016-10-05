# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long *pf=new long long[10];
	for (int i=0;i<10;i++)
		{
		pf[i]=pow(i,5);
		//cout<<pf[i]<<"\t";
		}
	long int num;
	long long sum=0;
	for (long int i=2;i<355000;i++)
		{
		num=i;
		long int temp=0;
		while(num!=0)
			{
			temp=temp+pf[num%10];
			num=num/10;
			}
		if (i==temp)
			{
			sum=sum+i;
			}
		}
	cout<<sum;
	return 0;
	}