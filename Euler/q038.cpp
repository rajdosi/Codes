# include <bits/stdc++.h>
using namespace std;

bool *mark=new bool[10];

bool ispan(int *s)
	{
	for (int i=0;i<10;i++)
		mark[i]=0;
	for (int i=0;i<9;i++)
		{
		if (mark[s[i]]==1 || s[i]==0)
			return 0;
		mark[s[i]]=1;
		}
	return 1;
	}

int main()
	{
	int arr[9]={0};
	for (long long i=9499;i>=9000;i--)
		{
		long long n=2*i;
		int j=8;
		while(n)
			{
			arr[j]=n%10;
			n=n/10;
			j--;
			}
		n=i;
		while(n)
			{
			arr[j]=n%10;
			n=n/10;
			j--;
			}
		if(ispan(arr))
			{
			for (int i=0;i<9;i++)
				cout<<arr[i];
			break;
			}
		
		}
	cout<<endl;
	return 0;
	}