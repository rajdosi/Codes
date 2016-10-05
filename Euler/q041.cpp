# include <bits/stdc++.h>
using namespace std;

//can be further optimized by using a divisibilty check by 5;


bool *seive= new bool[31428];
vector <long int> P;
vector <int> V;

bool isprime(long long p)
	{
	for (vector<long int>:: iterator it=P.begin();it!=P.end();it++)
		{
		if (p%(*it)==0)
			return false;
		}
	return true;
	}

void perm(int num,int size)
	{
	if (num==size)
		{
		long long sum=0;
		for (int i=0;i<size;i++)
			sum=sum+(V[i]*pow(10,size-i-1));
		if (isprime(sum))
			{
			cout<<sum<<endl;
			exit(0);
			}
		return;
		}
	for (int i=num;i<size;i++)
		{
		int temp=V[num];
		V[num]=V[i];
		V[i]=temp;
		perm(num+1,size);
		temp=V[num];
		V[num]=V[i];
		V[i]=temp;
		}
	return;
	}

int main()
	{
	seive[0]=seive[1]=1;
	for (int j=9;j>=1;j--)
		V.push_back(j);	
	int sum=0;
	for (long int i=2;i<31428;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<31428;j=j+i)
				seive[j]=true;
			P.push_back(i);
			}
		}	
	for (int i=0;i<9;i++)
		{
		sum=0;
		for (int j=0;j<9-i;j++)
			sum=sum+V[j];
		if (sum%3!=0)
			perm(0,9-i);
		V.erase(V.begin());
		}	
	cout<<endl;
	return 0;
	}