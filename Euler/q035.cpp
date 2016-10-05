# include <bits/stdc++.h>
using namespace std;

int main()
	{
	bool *seive=new bool[1000000];
	bool *mark=new bool[1000000];
	vector <long int> V;
	long int total=4;
	seive[0]=1;
	seive[1]=1;
	for (long int i=0;i<1000;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<1000000;j=j+i)
				seive[j]=true;
			}
		}
	for (long int i=10;i<1000000;i++)
		{
		if (seive[i]==false)
			V.push_back(i);
		}
	for (vector <long int>::iterator it=V.begin();it!=V.end();it++)
		{
		long int num=*it;
		int count=0;
		while (num)
			{
			count++;
			num=num/10;
			}
		num=*it;
		int flag=0;
		while(seive[num]==0)
			{
			int temp=num%10;
			num=num/10;
			num=num+(temp*pow(10,count-1));
			if (num==(*it))
				{
				flag=1;
				break;
				}
			}
		if (flag==1)
			{
			cout<<*it<<"\t";
			total++;
			}
		}
	cout<<total;
	cout<<endl;
	return 0;
	}