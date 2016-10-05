# include <bits/stdc++.h>
using namespace std;

bool *seive=new bool[10001];
vector <int> V;

bool isperm(int num1,int num2)
	{
	int arr1[10]={0},arr2[10]={0};
	while(num1)
		{
		arr1[num1%10]++;
		arr2[num2%10]++;
		num1=num1/10;
		num2=num2/10;
		}	
	for (int i=0;i<10;i++)
		{
		if (arr1[i]!=arr2[i])
			return false;
		}
	return true;
	}

int main()
	{
	seive[0]=seive[1]=1;
	for (int i=2;i<10001;i++)
		{
		if (seive[i]==false)
			{
			if (i>1000)
				V.push_back(i);
			for (int j=i*i;j<10001;j=j+i)
				seive[j]=true;			
			}
		}
	for (int i=0;i<V.size();i++)
		{
		for (int j=i+1;j<V.size();j++)
			{
			int k=V[j]+(V[j]-V[i]);
			if (!seive[k] && k<10000)
				{
				//cout<<V[i]<<"\t"<<V[j]<<"\t"<<k<<"\n";
				if (isperm(V[i],V[j]) && isperm(V[i],k))
					{
					cout<<V[i]<<"\t"<<V[j]<<"\t"<<k<<endl;
					break;
					}
				}
			}
		}
	cout<<endl;
	return 0;
	}