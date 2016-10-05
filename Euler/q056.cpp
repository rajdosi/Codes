# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int ma,mb,md=INT_MIN;
	for (int i=11;i<100;i++)
		{
		int n=i,mul1[200]={0},s=2,d1,d2,mul2[200]={0};
		d1=mul1[199]=n%10;
		d2=mul1[198]=n/10;
		int sum=mul1[199]+mul1[198];		
		for (int j=2;j<100;j++)
			{
			int carry=0;
			sum=0;
			for (int k=0;k<s;k++)
				{
				mul2[199-k]=mul1[199-k]*d1+carry;
				if (mul2[199-k]>=10)
					{
					carry=mul2[199-k]/10;
					mul2[199-k]=mul2[199-k]%10;
					}
				else
					carry=0;
				}
			if(carry!=0)
				{
				s++;
				mul2[200-s]=carry;
				}
			carry=0;
			for (int k=0;k<s;k++)
				{
				mul2[198-k]=mul2[198-k]+(mul1[199-k]*d2)+carry;
				if (mul2[198-k]>=10)
					{
					carry=mul2[198-k]/10;
					mul2[198-k]=mul2[198-k]%10;
					}
				else
					carry=0;
				}
			s++;
			if(carry!=0)
				{
				s++;
				mul2[200-s]=carry;
				} 
			for (int k=0;k<s;k++)
				{
				mul1[200-s+k]=mul2[200-s+k];
				sum=sum+mul2[200-s+k];
				if (sum>md)
					{
					md=sum;
					ma=i;
					mb=j;
					}
				}
			} 
		}
	cout<<ma<<"\t"<<mb<<"\t"<<md;
	cout<<endl;
	return 0;
	}