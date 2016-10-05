# include <bits/stdc++.h>
using namespace std;

int isdpal(long int num)
	{
	long int n=num;
	int count=0;
	while(num!=0)
		{
		count++;
		num=num/10;
		}
	int *pal=new int[count];
	num=n;
	for (int i=count-1;i>=0;i--)
		{
		pal[i]=num%10;
		num=num/10;
		}
	for (int i=0,j=count-1;i<count/2;i++,j--)
		{
			if (pal[i]!=pal[j])
				return 0;
		}
	return 1;
	}

int isbpal(long int num)
	{
	long int n=num;
	int p=0;
	while (num)
		{
		p++;
		num=num/2;
		}
	bool *pal=new bool[p];
	int k=p;
	p--;
	num=n;
	while(num!=0)
		{
		if (num%2==0)
			pal[p]=0;
		else
			pal[p]=1;
		num=num/2;
		p--;
		}
	// for(int i=0;i<k;i++) 
	// 	cout<<pal[i];
	for (int i=0,j=k-1;i<k/2;i++,j--)
		{
			if (pal[i]!=pal[j])
				return 0;
		}
	return 1;
	}

int main(){
	long long sum=0;
	for (long int i=1;i<1000000;i++)
		{
		if (isdpal(i) && isbpal(i))
			sum=sum+i;
		}
	cout<<sum;	
	cout<<endl;
	return 0;
}