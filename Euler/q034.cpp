# include <bits/stdc++.h>
using namespace std;

long long fact(int num)
	{
	if (num==1 || num==0)
		return 1;
	return num*fact(num-1);
	}


int main()
	{
	long int *fac=new long int[10],num;
	long long sum=0;
	for (int i=0;i<10;i++)
		fac[i]=fact(i);
	for (long int i=3;i<9999999;i++)
			{
			num=i;
			long long temp=0;
			while(num)
				{
				temp=temp+fac[num%10];
				num=num/10;
				}
			if (temp==i)
				sum=sum+i;
			}
	cout<<sum;
	cout<<endl;
	return 0;
	}