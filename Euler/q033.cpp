# include <bits/stdc++.h>
using namespace std;

long int gcd(int a,int b)
	{
	while(a!=b)	
		{
		if (a>b)
			a=a-b;
		else
			b=b-a;	
		}
	return a;
	}

int main()
	{
	long long prod=1;
	for (int i=11;i<=98;i++)
		{
		if (i%10==0)
			continue;
		for (int j=i+1;j<=99;j++)
			{
			int num1=i,num2=j;
			float divi,d;
			if (j%10==0)
				continue;
			if (num1%10==num2%10)
				divi=(float)(num1/10)/(float)(num2/10);
			else if (num1/10==num2/10)
				divi=(float)(num1%10)/(float)(num2%10);
			else if (num1%10==num2/10)
				divi=(float)(num1/10)/(float)(num2%10);
			else if (num1/10==num2%10)
				divi=(float)(num1%10)/(float)(num2/10);
			else 
				continue; 
			//cout<<divi<<"\t";
			d=(float)num1/(float)num2;
			if (divi==d)
				{
				long g=gcd(num1,num2);
				cout<<num1<<"\t"<<num2<<"\t"<<num2/g<<"\n";
				prod=(prod*num2/g)/(num1/g);
				}
			}
		}
	cout<<endl;
	cout<<prod;
	cout<<endl;
	return 0;
	} 