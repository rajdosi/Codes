# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int n;
	cin>>n;
	int *a=new int[n];
	int *l=new int[n];
	for (int i=0;i<n;i++)
		{
		cin>>a[i];
		l[i]=1;
		}

	for (int i=1;i<n;i++)
		for (int j=0;j<i;j++)
			if (a[i]>a[j] && l[i]<l[j]+1)
				l[i]=l[j]+1;
	int max=0;
	
	for (int i=0;i<n;i++)
		{
		if (max<l[i])
			max=l[i];
		}
	cout<<max<<endl;
	
	return 0;
	}

/* A method with o(nlogn) time complexity is also possible where you have to make various strings and replace them accordingly..
With each input try to change the matrix array and a binary search to find index of the last element of each array... 