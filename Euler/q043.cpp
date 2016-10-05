# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int divi[7]={2,3,5,7,11,13,17};
	int arr[10]={1,2,3,4,5,6,7,8,9,0};
	long long sum=0;
	do{
		int flag=0;	
		for (int i=1;i<8;i++)
			{
			if(((arr[i]*100)+(arr[i+1]*10)+(arr[i+2]))%divi[i-1]!=0)
				{
				flag=1;	
				break;
				}
			}
		if (flag==0)
			{		
			long long temp=0;
			for (int i=0;i<=9;i++)
				temp=temp+(arr[i]*pow(10,9-i));
			sum=sum+temp;
			}		
		}while(next_permutation(arr,arr+10));
	cout<<sum;
	cout<<endl;
	return 0;
	}