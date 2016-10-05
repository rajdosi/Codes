# include <bits/stdc++.h>
using namespace std;

int main()
	{
	long long sum=0;
	bool arr[1000]={0};
	for(int i=3;i<1000;i=i+3)
		{
		arr[i]=true;
		sum=sum+i;
		cout<<i<<"\t"<<sum<<endl;
		}
	for (int i=5;i<1000;i=i+5)
		{
		if(arr[i]==false)
			{
			sum=sum+i;
			arr[i]=true;
			}
		}
	cout<<sum<<endl;
	return 0;	
	}