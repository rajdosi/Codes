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
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	bool *b=new bool[10];
	int count=0;
	long long p=1000000;
	count=0;
	int	i=0;
	while(p-fact(9-i)>0)
			{
			p=p-fact(9-i);
			count++;
			}
	cout<<a[count];
	b[count]=1;
	int flag=0;
	for (i=1;i<10;i++)
		{
		cout<<endl;
		count=0;
		while(p-fact(9-i)>0)
			{
			p=p-fact(9-i);
			count++;
			}
		int j=0,k=0;
		for (j=0;j<10;j++)
			{
			if(b[j]==0)
				{
				if(k==count)
					break;
				k++;
				}
			}
		cout<<a[j];	
		b[j]=i;
		//cout<<count<<endl;
		}
	return 0;
	}