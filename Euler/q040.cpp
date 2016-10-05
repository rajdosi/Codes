# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int d[7]={0};
	long int find=1,j=0;
	long int num=0;
	long int pro=1;
	for (long int i=1;j<7;i++)
		{
		int length=0;
		long int n=i;
		while (n)
			{
			length++;
			n=n/10;
			}
		num=num+length;
		if (find<=num)
			{
			int k=num-find;
			find=find*10;
			n=num-k;
			int l=n-(num-length);
			k=length-l+1;
			n=i;
			int f;
			while (k--)
				{
				f=n%10;
				n=n/10;
				}
			d[j]=f;
			j++;
			cout<<num<<"\t"<<i<<"\t"<<d[j-1]<<"\t"<<j<<"\t"<<length<<"\t"<<f<<endl;
			}
		//cout<<num<<"\t"<<i<<"\n";
		}
	cout<<endl;
	for (int i=0;i<7;i++)
		pro=pro*d[i];
	cout<<pro;
	cout<<endl;
	return 0;
	}