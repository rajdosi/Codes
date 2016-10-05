# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int upper=1;
	long int max=LONG_MIN;
	int index;
	for (int i=7;i<1000;i++)
		{
		upper=10;
		int *rem=new int[i];
		int j=0;
		int flag=0;
		while(upper%i!=0)
			{
			rem[j]=upper%i;
			upper=upper%i;
			upper=upper*10;
			for (int i=0;i<j;i++)
				{
				if(rem[i]==rem[j])
					flag=1;
				}
			if (flag==1)
				{
				break;
				}
			j++;
			}
		if(upper%i==0)
			j=0;
		if(max<j)
			{
			max=j;
			index=i;
			}
		}
	cout<<index<<"\t"<<max;
	return 0;
	} 