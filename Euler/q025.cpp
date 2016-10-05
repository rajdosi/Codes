# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int a[1000]={0};
	int b[1000]={0};
	b[999]=1;
	int c[1000]={0};
	int carry=0;
	for(int j=2;;j++)
		{
		for (int i=999;i>=0;i--)
			{
			c[i]=a[i]+b[i]+carry;
			carry=0;
			if (c[i]>=10)
				{
				carry=c[i]/10;
				c[i]=c[i]%10;
				}
			a[i]=b[i];
			b[i]=c[i];
			}
		if (c[0]>0)
			{
			cout<<j;
			// for (int i=0;i<1000;i++)
			// 	cout<<c[i];
			break;
			}
		}
	return 0;
	}