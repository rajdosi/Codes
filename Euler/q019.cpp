# include <bits/stdc++.h>
using namespace std;

string checkday(int num)
	{
	switch(num)
		{
			case 0:
				return "Monday";
			case 1:
				return "Tuesday";
			case 2:
				return "Wednesday";
			case 3:
				return "Thursday";
			case 4:
				return "Friday";
			case 5:
				return "Saturday";
			case 6:
				return "Sunday";
		}
	}


int checkmonth(int num)
	{
	switch(num)
		{
			case 0:
				return 2;
			case 1:
				return 0;
			case 2:
				return 2;
			case 3:
				return 1;
			case 4:
				return 2;
			case 5:
				return 1;
			case 6:
				return 2;
			case 7:
				return 2;
			case 8:
				return 1;
			case 9:
				return 2;
			case 10:
				return 1;
			case 11:
				return 2;
		}
	}

int main()
	{
	int day=0;
	day=day+365;
	day=day%7;
	int sun=0;
	for (int i=1901;i<2001;i++)
		{
		for (int j=0;j<12;j++)
			{
			if(checkmonth(j)==2)
				{
				day=day+31;
				day=day%7;
				if(checkday(day)=="Sunday")
					sun=sun+1;
				}
			else if(checkmonth(j)==1)
				{
				day=day+30;
				day=day%7;
				if(checkday(day)=="Sunday")
					sun=sun+1;
				}
			else 
				{
				if (i%4==0)
					day=day+29;
				else
					day=day+28;
				day=day%7;
				if(checkday(day)=="Sunday")
					sun=sun+1;
				}
			}
		}
	cout<<sun;
	cout<<endl;
	return 0;
	}	