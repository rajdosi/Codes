# include <bits/stdc++.h>
using namespace std;

vector <int> V;
bool seive[10000]={false};

long long factor(int mod)
	{
	long long temp=1;
	int num=mod;
	int count;
	// for (vector<int> ::iterator it=V.begin();it!=V.end();it++)
	//  	cout<<*it<<"\t";
	for (vector <int>::iterator it=V.begin();it!=V.end();it++)
		{
		count=*it;
		//cout<<mod<<"\t"<<count<<"\t"<<count*count<<"\t"<<mod%*it<<"\t"<<sqrt(num)<<"\n";
		if (count*count<=num)
			{
			while(mod%*it==0)
				{
				//cout<<mod<<"\t"<<count<<"\n";
				mod=mod/(*it);
				count=count*(*it);
				}
			temp=temp*(count-1)/((*it)-1);
			}
		else	
			{
			if(mod>1)
				temp=temp*(mod+1);
			return temp-num;
			}
		}
	}

int main()
	{
	long int *dp=new long int[10000];
	long long sum=0;
	bool *mark=new bool[10000];
	dp[1]=0;
	seive[1]=1;
	seive[0]=1;
	for (int i=2;i<10000;i++)
		{  
		if (seive[i]==0)
			{
			for (int j=i*i;j<10000;j=j+i)
				seive[j]=1;
			dp[i]=1;
			V.push_back(i);
			}
		}	
	//memset(seive,0,sizeof(seive));
	for (int i=4;i<=9999;i++)
		{
		if(seive[i]==1)
			dp[i]=factor(i);
		if (dp[dp[i]]==i && dp[i]!=i && mark[i]!=1)
			{
			cout<<dp[i]<<"\t"<<i<<"\n";
			sum=sum+dp[i]+i;
			}
		}
	cout<<sum;
	return 0;
	}