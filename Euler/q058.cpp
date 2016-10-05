# include <bits/stdc++.h>
using namespace std;

bool *seive=new bool[700000000];

int main()
	{
	bool NF=true;
	seive[0]=seive[1]=true;
	for (int i=2;i<40000;i++)
		{	
		if (!seive[i])
			{
			for (int j=i*i;j<700000000;j=j+i)
				seive[j]=true;
			}
		}
	long long a=3,b=5,c=7,d=9;
	long long length=3,tc=5,pc=3;
	while (NF)
		{
		//cout<<length<<"\n";
		a=a+(8*(length/2))+2;
		b=b+(8*(length/2))+4;
		c=c+(8*(length/2))+6;
		if (!seive[a])
			pc++;
		if (!seive[b])
			pc++;
		if (!seive[c])
			pc++;	
		length=length+2;
		tc=tc+4;
		if (float(float(pc)/float(tc))<0.1)
			{
			NF=false;
			break;
			}
		}
	cout<<length;
	cout<<endl;
	return 0;
	}