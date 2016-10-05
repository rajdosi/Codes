# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int t;
	cin>>t;
	while (t--)
		{
		string str; 
		cin>>str;
		long long cr=0;	
		long long i=0;	
		while (str[i]=='R')
		 	i++;
		long long max=LONG_MIN,temp=0,index1=i,index2=i,i1=i;
		for (;i<str.length();i++)
			{
			if (str[i]=='K')
				temp++;
			else
				temp--;
			if (temp<0)
				{
				i1=i+1;
				temp=0;
				}
			if (temp>max)
				{
				index1=i1;
				index2=i;
				max=temp;
				}
			}
		// cout<<"\n"<<str.length()<<"\t"<<index1<<"\t"<<index2<<"\t"<<max<<"\t";
		for (i=0;i<index1;i++)
			{
			if (str[i]=='R')
				cr++;
			}
		for (i=index1;i<=index2;i++)
			{
			if (str[i]=='K')
				cr++;
			}	
		for (i=index2+1;i<str.length();i++)
			{
			if (str[i]=='R')
				cr++;
			}
		if (max<0)
			cr--;
		cout<<cr<<endl;
		}
	return 0;
	}