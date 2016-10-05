# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long pro=1;
	int j,prime[]={2,3,5,7,11,13,17,19};
	for (int i=0;i<8;i++)
		{
		j=1;
		while(pow(prime[i],j)<20)
			{
			pro=pro*prime[i];
			j++;
			}
		cout<<pro<<endl;
		}
	return 0;
	}