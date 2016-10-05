# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long a,b,c;
	int *pyth=new int[1002]; 
	int sum=1000;
	int max=INT_MIN,index;
	for (a=1;a<sum/3+1;a++)
		{
		for (b=a;b<sum/2+1;b++)
			{
			for (c=b;c<=1000-a-b;c++)
				{
				if (c*c==a*a+b*b)
					{
					pyth[a+b+c]++;
					}
				}
			}
		}
	for (int i=0;i<=1000;i++)
		{
		if (pyth[i]>max)
			{
			max=pyth[i];
			index=i;
			}
		}
	cout<<index<<"\t"<<max;
	cout<<endl;
	return 0; 
	}