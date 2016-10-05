# include <bits/stdc++.h>
using namespace std;

vector <int> V;

int main(){
	bool *seive=new bool[200001];
	int a,b,n;
	long int final;
	long long max=LONG_MIN;
	int index1,index2;
	seive[1]=1;
	seive[0]=1;
	for (long int i=2;i<(200001);i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<200001;j=j+i)
				seive[j]=1;
			if (i<1000)
				V.push_back(i);
			}
		}
	//sort(V.end(),V.begin());
	// for (vector <int>:: iterator it=V.end()-1;it!=V.begin();it--)
	// 	cout<<*it<<"\t";
	for (vector <int>:: iterator it=V.end()-1;it!=V.begin();it--)
		{
		a=*it;
		for(b=-1000;b<=1000;b++)
			{
			long int count=1;
			for (n=1;;n++)
				{
				final=(n*n)+(b*n)+a;
				if(final>=0)
					{
					if (seive[final]==0)
						count++;
					else
						break;
					}
				else
					break;
				}
			if(count>max)
				{
				max=count;
				index1=a;
				index2=b;
				}
			}
		}
	long long pro;
	pro=index1*index2;
	cout<<pro<<"\t"<<index1<<"\t"<<index2<<"\t"<<max<<"\n";
	return 0;
}