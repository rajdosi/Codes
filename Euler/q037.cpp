# include <bits/stdc++.h>
using namespace std;

int main()
	{
	bool *seive=new bool[4000000];
	seive[1]=seive[0]=1;
	set <long long> arr;
	long long sum=0;
	int app[]={1,2,3,5,7,9};
	arr.insert(1);
	arr.insert(2);
	arr.insert(3);
	arr.insert(5);
	arr.insert(7);
	arr.insert(9);
	int count=0;
	for (long int i=2;i<2000;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<4000000;j=j+i)
				seive[j]=1;
			}
		}
	int i=0,j=0;
	while (count<11)
		{
		set <long long>::iterator it=arr.begin();
		long long in=*it;	
		//cout<<in<<"\t";
		arr.erase(it);
		if (seive[in]==0)
			{
			//cout<<in<<"\t";
			long int length=1;
			long long n=in;
			bool x=true;
			while (n>0)
				{
				if(seive[n])
					x=false;
				n=n/10;
				length=length*10;
				}
			//cout<<in<<"\t"<<x<<"\t"<<length<<"\t"<<count<<endl;
			if (x==true && length>10)
					{
					sum=sum+in;
					count++;	
					}	
			for (i=0;i<6;i++)
				{
				arr.insert((app[i]*length)+in);
				}	
			}
		}
	cout<<endl;
	cout<<sum;
	cout<<endl;
	return 0;
	}