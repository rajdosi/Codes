# include <bits/stdc++.h>
using namespace std;

int *dp=new int[1000000];

long long collatz(long long num)
	{
	//cout<<num<<"\t";
	if (num==1)
		return 0;
	if (num%2==0)
		{
		if(num<333334)
			{
			if (dp[num/2]==0)
				dp[num/2]=collatz(num/2)+1;
			return dp[num/2];
			}
		else
			return collatz(num/2)+1;
		}
	else if(num%2==1)
		{
		if(num<333334)
			{
			if(dp[(3*num)+1]==0)
				dp[(3*num)+1]=collatz((3*num)+1)+1;		
			return dp[(3*num)+1];
			}
		else	
	    	return collatz((3*num)+1)+1;		
		}
	}

int main()
	{
	long int index,i;
	long long max=LLONG_MIN;
	dp[1]=1;
	for (i=2;i<1000000;i++)
 	  	{
		if (dp[i]==0)
			dp[i]=collatz(i)+1;
		if (dp[i]>max)
	 		{
	 		max=dp[i];
	 		index=i;
	 		}
		}
	cout<<index<<"\t"<<max<<"\n";	
	return 0;
	}