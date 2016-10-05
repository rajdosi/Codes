# include <bits/stdc++.h>
using namespace std;

bool isperm(long long num1,long long num2)
	{
	int a1[10]={0},a2[10]={0};
	while (num1)
		{
		a1[num1%10]++;
		a2[num2%10]++;
		num1/=10;
		num2/=10;
		}
	for (int i=0;i<10;i++)
		{
		if (a1[i]!=a2[i])
			return false;
		}
	return true;
	}


int main()
	{
	bool NF=true;
	long long num=1;
	while(NF)
		{
		num=num*10;
		for (long long i=num;i<(num*10)/6+1;i++)
			{
			int flag=0;
			for (int j=2;j<7;j++)
				{
				if (isperm(i,i*j)==false)
					{
					flag=1;
					break;
					}
				}
			if(flag==0)
				{
				NF=false;
				cout<<i;
				break;
				}
			}
		}
	cout<<endl;
	return 0;
	}