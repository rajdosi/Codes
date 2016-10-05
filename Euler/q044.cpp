# include <bits/stdc++.h>
using namespace std;

bool ispent(long long num)
	{
	double pro=(sqrt(1+num*24)+1.0)/6.0;
	return pro==((int)pro);
	}

int main()
	{
	bool found=true;
	int i=1;
	while (found)
		{	
		i++;
		long int n=i*(3*i-1)/2;
		//cout<<i<<"\t"<<n<<"\n";
		for (int j=1;j<i;j++)
			{
			long int m=j*(3*j-1)/2;
			if (ispent(n+m) && ispent(n-m))
				{
				cout<<n<<"\t"<<m<<"\t"<<n-m;
				found=false;
				break;	
				}
			}
		}
	cout<<endl;
	return 0;
	}