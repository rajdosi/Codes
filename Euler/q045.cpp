# include <bits/stdc++.h>
using namespace std;

bool ispent (long long num)
	{
	double pro=(sqrt(1.0+24*num)+1.0)/6.0;
	return pro==((int)pro);
	}	

int main()
	{
	int i=144;
	bool NF=true;
	while(NF) 
		{
		long long n=i*(2*i-1);
		if(ispent(n))
			{
			cout<<n;	
			NF=false;
			}
		i++;
		}
	cout<<endl;
	return 0;
	}