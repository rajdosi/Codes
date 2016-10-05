# include <bits/stdc++.h>
using namespace std;

int main()
{
	set <double> ans;
	for (int a=2;a<=100;a++)
	{
		for (int b=2;b<=100;b++)
		{
		ans.insert(pow(a,b));
		}
	}
	cout<<ans.size();
	return 0;
}