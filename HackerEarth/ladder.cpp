# include <bits/stdc++.h>
using namespace std;

long long check(long long a)
	{
	if (a>1000000007)
		a=a%1000000007;
	return a;
	}

int main()
	{
	long long t,n;
	cin>>t>>n;
	long long *way=new long long[1000005];
	long long *arr1=new long long[1000005];
	way[2]=1;way[5]=1;way[4]=1;
	for (long long i=6;i<=n;i++)
		{
		way[i]=check(way[i-2]+way[i-5]);
		}
	while(t--)
		{
		long long cur,k;
		cin>>cur>>k;
		if (k==2 || k==5 || k>cur)
			cout<<way[cur]<<endl;
		else if (k==cur)
			cout<<check(way[cur]+1)<<endl;
		else
			{
			for(long long int i = 0; i < k; i++)
				arr1[i] = way[i];
			arr1[k]=check(way[k]+1);
			for (long long i=k+1;i<=cur;i++)
				{
				arr1[i]=check(arr1[i-2]+arr1[i-5]+arr1[i-k]);
				}
			cout<<arr1[cur]<<endl;
			}
		}
	return 0;
	}