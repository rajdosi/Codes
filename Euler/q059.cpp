# include <bits/stdc++.h>
using namespace std;

int main()
	{
	ifstream in;
	int ct[2000]={0};
	int hist[100]={0};
	int ptr=0;
	in.open("cipher.txt");
	while (!in.eof())
		{
		char a;
		in.get(a);
		if (int(a)>=48 && int(a)<=57)
			ct[ptr]=ct[ptr]*10+(int(a)-48);
		else	
			{
			hist[ct[ptr]]++;
			ptr++;
			}
		}
	in.close();
	ptr--;
	char pt;
	int max=INT_MIN;
	char d[3];
	long long sum=0;
	char key[3]={'a','a','a'};
	while (int(key[0])!=123)
		{
		int temp=0;
		long long tmp2=0;
		for (int i=0;i<ptr;i++)
			{
			pt=ct[i]^key[i%3];
			tmp2=tmp2+int(pt);
			if ((int(pt)>=97 && int(pt)<=122) || int(pt)==32)
				temp++;
			}
		if (temp>max)
			{
			max=temp;
			sum=tmp2;
			d[2]=key[2];
			d[1]=key[1];
			d[0]=key[0];
			}
		key[2]++;
		if (int(key[2])>122)
			{
			key[2]=97;
			key[1]++;
			if (int(key[1])>122)
				{
				key[1]=97;
				key[0]++;
				}
			}
		}
	cout<<d[0]<<d[1]<<d[2]<<"\t"<<sum;
	cout<<endl;
	return 0;	
	}


// for (int i=0;i<ptr;i++)
	// 	cout<<ct[i]<<"\t";
	