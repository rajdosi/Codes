# include <bits/stdc++.h>
using namespace std;

bool *mark=new bool[355000];

void perm(int *a,int num,int size)
	{
	if (num==4)
		{
		for (int i=0;i<4;i++)
			cout<<a[i];
		cout<<endl;
		return;
		}
	int temp;
	for (int i=num;i<size;i++)
		{
		temp=a[num];
		a[num]=a[i];
		a[i]=temp;
		perm(a,num+1,4);
		temp=a[num];
		a[num]=a[i];
		a[i]=temp;
		}
	}

int main()
	{
	int a[4]={1,2,3,4};
	perm(a,0,4);
	return 0;
	}