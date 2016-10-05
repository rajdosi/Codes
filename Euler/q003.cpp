# include<bits/stdc++.h>
using namespace std;


int main()
	{
	vector <long int> V;
	bool seive[1000001];
	seive[0]=true;
	seive[1]=true;
	long int i;
	long long x=600851475143;
	for (i=2;i<775146;i++)
		{
		if (seive[i]==false)
			{
			V.push_back(i);
			for (long int j=i*i;j<=775146;j=j+i)
				seive[j]=true;
			// cout<<i<<"\t";
			}
		}
	while (!V.empty())
		{
		i=V.back();
		V.pop_back();
		if (x%i==0)
			{
			cout<<i;
			break;
			}
		}
	return 0;
}