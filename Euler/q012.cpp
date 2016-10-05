# include <bits/stdc++.h>
using namespace std;

int main()
	{
	vector <long int> V;
	int coun=1,j;
	long int tn,temp;
	long long ftn=1;
	bool seive[1000]={false};
	seive[0]=1;
	seive[1]=1;
	for (int i=2;i<1000;i++)
		{
		if (seive[i]==false)
			{
			V.push_back(i);
			for (j=i*i;j<1000;j=j+i)
				seive[j]=1;
			//cout<<i<<"\t";
			}
		}
	cout<<endl;
	// cout<<endl<<endl<<endl;
	// for (vector <long int>::iterator it=V.begin();it!=V.end();it++)	
	// 	cout<<*it<<"\t";
	for (long int i=1;;i++)
		{
		tn=(i*(i+1))/2;
		temp=tn;
		j=0;
		ftn=1;
		int sq=tn;
		for (vector <long int>::iterator it=V.begin();it!=V.end();it++,j++)
			{
			coun=1;
			if(tn==1)
				break;
			int m=*it;
			if (m>sq)
				break;
			while(tn%m==0)
				{
				coun++;
				tn=tn/m;
				}
			ftn=ftn*(coun);
			}
		if(ftn>=500)
			{
			cout<<temp;
			exit(0);
			}
		cout<<endl<<endl;
		}
	return 0;	
	}