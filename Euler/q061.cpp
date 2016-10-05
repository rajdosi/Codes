# include <bits/stdc++.h>
using namespace std;

int cnt[6]={0},sol[6]={0};
vector <int> num[6];
bool mark[6]={false};

vector <int> gen(int type)
	{
	vector <int> temp;
	int number,n=0;
	while (number<10000)
		{
		switch(type)
			{
					case 0:
                        //Triangle numbers
                        number = n * (n + 1) / 2;
                        break;
                    case 1:
                        // Square numbers
                        number = n * n;
                        break;
                    case 2:
                        // Pentagonal numbers
                        number = n * (3 * n - 1) / 2;
                        break;
                    case 3:
                        //Hexagonal numbers
                        number = n * (2*n - 1);
                        break;
                    case 4:
                        //Heptagonal numbers
                        number = n * (5 * n - 3) / 2;
                        break;
                    case 5:
                        //Octagonal numbers
                        number = n * (3 * n - 2);
                        break;	
			}
		if (number>999 && number<10000)
			{
			cnt[type]++;
			temp.push_back(number);
			}
		n++;
		}
	return temp;
	}

void disp()
	{
	for (int i=0;i<6;i++)
		{
		for (vector <int>::iterator it=num[i].begin();it!=num[i].end();it++)
			{
			cout<<*it<<"\t";
			}
		cout<<endl<<endl<<endl;
		}
	}

bool recur(int length)
	{
	if (length==6)
		{
		if (sol[5]%100==sol[0]/100)
			return true;
		else
			return false;
		}
	for (int type=0;type<5;type++)
		{
		if (mark[type]==false)
			{
			for (vector <int>::iterator it=num[type].begin();it!=num[type].end();it++)
				{
				if (*it%100==sol[5-length+1]/100)
					{
					mark[type]=true;
					sol[5-length]=*it;
					if (recur(length+1))
						return true;
					}
				}		
			mark[type]=false;
			sol[type-1]=0;
			}
		}
	return false;
	} 

int main()
	{
	for (int i=0;i<6;i++)
		{
		num[i]=gen(i);
		}
	// disp();
	for (vector <int>::iterator it=num[5].begin();it!=num[5].end();it++)
		{
		mark[5]=true;
		sol[5]=*it;
		if (recur(1))
			break;
		}
	int sum=0;
	for (int i=0;i<6;i++)
	 	sum=sum+sol[i];
	cout<<sum<<endl;
	return 0;	
	}