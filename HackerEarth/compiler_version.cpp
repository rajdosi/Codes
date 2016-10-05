# include <bits/stdc++.h>
using namespace std;

vector <string> V,F;

int main()
	{
	char a[60];
	while(1)
		{
		string s;
		char ch;
		scanf("%[^\n]",a);
		cin.get(ch);
		if (ch==EOF)
			break;
		s=a;
		V.push_back(s);
		}	

	for (int i=0;i<V.size();i++)
		{
		string str;
		str=V[i];
		int p=str.find("//");
		string s1=str,s2="";
		if (p!=string::npos)
			{
			s1=str.substr(0,p);
			s2=str.substr(p);
			}
		int np;
		while ((np=s1.find("->"))!=string::npos)
			{
			s1.replace(np,2,".");
			}
		F.push_back(s1+s2);
		}

	for (int i=0;i<F.size();i++)
		cout<<F[i]<<endl;
	return 0;
	}