# include <bits/stdc++.h>
using namespace std;

long int check(long long a)
	{
	if (a>100000)
		a=a%100000;
	return a;
	}


queue <long int> Q;

int main()
	{
	long int skey,fkey,*ok;
	bool val[100000]={0};
	int n;
	cin>>skey>>fkey>>n;
	ok=new long int[n];
	for (int i=0;i<n;i++)
		{
		cin>>ok[i];
		}
	Q.push(skey);
	Q.push(-1);
	val[skey]=1;
	int i=0;

	int turn=0;
	while (1)
		{
		long int temp=Q.front();
		if (temp==-1)
			{
			Q.pop();
			Q.push(-1);
			turn++;
			if (!Q.empty())
				temp=Q.front();
			}
		if (temp==fkey)
			{
			cout<<turn;
			return 0;
			}
		Q.pop();
		if(Q.empty())
			break;
		for (int i=0;i<n;i++)
			{
			long int var=check(temp)*check(ok[i]);
			var=check(var);
			if (val[var]==0)
				{
				Q.push(var);
				val[var]=1;
				}
			}
		}
	cout<<"-1";
	return 0;
	}