# include <bits/stdc++.h>
using namespace std;

bool *seive=new bool[1000001];
long long *squ=new long long[1000001];
vector <long long> V;	

int main()
	{
	long int i=4;
	bool NF=true;
	squ[0]=0;
	squ[1]=1;
	for (long int i=2;i<1000001;i++)
		squ[i]=i*i;
	seive[0]=seive[1]=1;
	for (long int i=2;i<6001;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<1000001;j=j+i)
				{
				seive[j]=1;
				}
			}
		else 
			{
			if (i%2==1)
				V.push_back(i);
			}
		}

	// for (int i=0;i<V.size();i++)
	// 	cout<<V[i]<<"\t";
	// cout<<endl<<endl<<V.size();
	for (int i=2000;NF==true;i++)
		{
		int flag=0;
		for (int j=1;V[i]-2*squ[j]>=0;j++)
			{
			if(!seive[V[i]-2*squ[j]])
				{
				cout<<V[i]<<"\t"<<squ[j]<<"\t"<<V[i]-squ[j]<<"\n";
				flag=1;
				break;
				}
			}
		if (flag==0)
			{
			cout<<V[i];
			NF=false;	
			}
		}
	cout<<endl;
	return 0;
	}