# include <bits/stdc++.h>
using namespace std;

vector <int> P,A;

long long factor (int num)
	{
	int mod=num;
	long long count;
	long long pro=1;
	for (vector <int>:: iterator it=P.begin();it!=P.end();it++)
		{
		count=*it;
		if (count*count<=num)
			{
			while (mod%*it==0)
				{
				mod=mod/(*it);
				count=count*(*it);
				}
			pro=pro*(count-1)/((*it)-1);
			}
		else
			{
			if(mod>1)
				pro=pro*(mod+1);
			return pro-num;
			}
		}
	if(mod>1)
			pro=pro*(mod+1);
	return pro-num;
	}




int main()
	{
	bool *seive=new bool[29000];
	bool *mark=new bool[28124];
	seive[1]=seive[0]=1;
	long long sum=0;
	for(int i=2;i<(int)sqrt(29000)+1;i++)
			{
			if (seive[i]==0)
				{
				for (int j=i*i;j<28124;j=j+i)
					seive[j]=1;
				P.push_back(i);
				}
			}
	for (int i=4;i<28124;i++)
		{
		if (seive[i]!=0)
			{
			//cout<<i<<"\t"<<factor(i)<<"\n";
			if (factor(i)>i)
				A.push_back(i);
			}
		}
	for (vector <int>::iterator it=A.begin();it!=A.end();it++)
			{
			for (vector <int>::iterator it2=it;it2!=A.end();it2++)
				{
				if ((*it+*it2)<28124)
					mark[*it+*it2]=1;
				}
			}
	for (int i=0;i<28124;i++)
		{
		if(mark[i]==0)
			sum=sum+i;
		}
	cout<<sum;
	return 0;
	}