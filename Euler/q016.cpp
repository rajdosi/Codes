# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int mul[1000]={0},carry=0,i,j,a=0;
	long int sum=0;
	mul[999]=1;
	for (i=0;i<1000;i++)
		{
		j=999;
		while (j)
	 		{
				mul[j]=(mul[j]*2)+carry;
				carry=0;
				if (mul[j]>=10)
					{
					carry=mul[j]/10;
					mul[j]=mul[j]%10;
					}
				j--;
			}
		}
	j=0;
	while(mul[j]==0)
		{
		j++;
		}
	for (i=j;i<1000;i++)
		{
			sum=sum+mul[i];
		}
	cout<<sum<<endl;
	return 0;
	}