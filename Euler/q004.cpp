# include <bits/stdc++.h>
using namespace std;

int checkpal(string pal)
	{
	int i,j;
	for (i=0,j=pal.length()-1;i<(pal.length()/2);i++,j--)
		{
			if(pal[i]!=pal[j])
				return 0;
		}
	return 1;
	}

int main()
	{
	int a=999,b=999;
	long int p,x;
	string pr;
	for (;a>=1;a--)
		{
		for(b=a;b>=1;b--)
			{
			p=a*b;
			pr=to_string(p);
			if (checkpal(pr) && p>x)
				{
				x=p;
				}
			}
		}
	cout<<x;
	return 0;
	}