# include <bits/stdc++.h>
using namespace std;

bool check(int *a,int *b,int s)
	{
	int c[1000]={0},carry=0;
	for (int j=0;j<s;j++)
		{
		c[999-j]=a[999-j]+b[999-j]+carry;
		if (c[999-j]>=10)
			{
			carry=c[999-j]/10;
			c[999-j]=c[999-j]%10;
			}
		else
			carry=0;
		}
	if (carry!=0)
		return true;
	else
		return false;
	}

int main()
	{
	int n[1000]={0},m[1000]={0},f[1000]={0},count=0,s=1;
	n[999]=1;
	m[999]=2;
	for (int i=1;i<1000;i++)
		{
		int carry=0;
		for (int j=0;j<s;j++)
			{
			f[999-j]=2*m[999-j]+n[999-j]+carry;
			n[999-j]=m[999-j];
			if (f[999-j]>=10)
				{
				carry=f[999-j]/10;
				f[999-j]=f[999-j]%10;
				}
			else
				carry=0;
			m[999-j]=f[999-j];
			}
		if (carry!=0)
			{
			s++;
			f[1000-s]=m[1000-s]=carry;
			}
		for (int j=0;j<s;j++)
			{
			cout<<f[1000-s+j];
			}
		cout<<endl;
		if (check(n,m,s))
		 	count++;
		}
	cout<<count;
	cout<<endl;
	return 0;
	}