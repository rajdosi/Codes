# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int a,b,c;
	for (a=0;a<334;a++)
		{
		for (b=0;b<500;b++)
			{
			c=1000-a-b;
			if ((a*a)+(b*b)==(c*c))
				{
				cout<<a*b*c;
				break;
				}
			}
		}
	return 0;
	}