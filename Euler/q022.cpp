# include <bits/stdc++.h>
using namespace std;

vector <pair <string,int> > P;

int main()
	{
	string s;
	long long sum=0;
	int count=0;
	ifstream RF;
	RF.open("names.txt");
	while(!RF.eof())
		{
		count++;
		sum=0;
		RF>>s;
		for(int i=0;isalpha(s[i]);i++)
			{
			sum=sum+(int)s[i]-64;	
			}	
		//cout<<s<<"\t"<<sum<<"\n";
		P.push_back(make_pair(s,sum));
		}
	RF.close();
	sort(P.begin(),P.end());
	sum=0;
	for (int i=0;i<count;i++)
		{
		sum=sum+((i+1)*(P[i].second));
		}	
	cout<<sum;
	return 0;
	}