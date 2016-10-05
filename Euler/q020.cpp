# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int fact[10000]={0};
	long int carry=0;
	long long sum=0;
	fact[9999]=1;
	int j;
	for (int i=2;i<100;i++)
		{
		j=9999;
		while(j)
			{
			fact[j]=fact[j]*i+carry;
			carry=0;
			if (fact[j]>=10)
				{
				carry=fact[j]/10;
				fact[j]=fact[j]%10;	
				}
			j--;
			}
		}
	for (int i=0;i<10000;i++)
		sum=sum+fact[i];
	cout<<sum;
	return 0;
	}