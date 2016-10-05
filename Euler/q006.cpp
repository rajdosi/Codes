# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long a=0,b=0;
	for (int i=0;i<=100;i++)
		{
		a=a+i;
		b=b+(i*i);
		}
	cout<<(a*a)-b;
	return 0;
	}