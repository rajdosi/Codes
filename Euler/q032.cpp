# include <bits/stdc++.h>
using namespace std;

bool *dig=new bool[10];

int ispan(string s)
	{
	for (int i=1;i<10;i++)
		dig[i]=0;
	if (s.length()!=9)
		return 0;
	else
		{
		for (int i=0;i<9;i++)
			{
			if (s[i]-48==0 || dig[s[i]-48]==1)
				return 0;
			dig[s[i]-48]=true;
			}
		return 1;
		}
	}
int main()
	{
	long long sum=0;
	set <long long> pro;
	for (int i=2;i<=98;i++)
		{
		long int j=(i>9)?123:1234;
		long int m=(i>9)?987:9876;
		int c;
		for (;j<=m;j++)
			{
			string l;
			ostringstream oss;
			oss<<i<<j<<(i*j);
			istringstream iss(oss.str());
			iss>>l;	
			c=ispan(l);
			//if(i==39 && j==186)
				//cout<<l<<"\t"<<c<<endl;
			if (c==1)
			 	{
			 	pro.insert(i*j);
			 	cout<<i*j<<"\t";
			 	}
			}
		}
	cout<<endl<<endl;
	for (set <long long>::iterator it=pro.begin();it!=pro.end();it++)
		sum=sum+(*it);
	cout<<sum;
	return 0;
	}