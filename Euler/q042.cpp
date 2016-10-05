# include <bits/stdc++.h>
using namespace std;

int main()
	{
	bool *tri=new bool[1000];
	for (int i=1;i<41;i++)
		tri[(i*(i+1))/2]=1;
	ifstream RF;
	RF.open("words.txt");
	string s;
	int count=0;
	char a;
	while (!RF.eof())
		{
		long int sum=0;
		while(RF.get(a))
			{
			if (a==',')
				{
				if (tri[sum]==1)
					count++;
				break;
				}
			if (a!='"')
				sum=sum+(a-64);
			}
		}
	RF.close();
	cout<<count;
	cout<<endl;
	return 0;
	}