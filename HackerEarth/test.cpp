# include <bits/stdc++.h>
using namespace std;

int main()
	{
	vector<string> v;
	string str;
	v.push_back("ajcahka");
	v.push_back("cahsaska");
	v.push_back("kaaaa");
	v.push_back("wdsahhka");
	v.push_back("bsfkbsja");
	for (int i=0;i<v.size();i++)
		{
		str=v[i];
		// cout<<str<<"\n";
		int a=str.find("z");
		if (a==string::npos)
			cout<<"a\n";

		}
	cout<<endl;
	return 0;
	}