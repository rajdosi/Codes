# include <bits/stdc++.h>
using namespace std;

int main()
	{
	int c=0;
	int f=0;
	ifstream in("poker.txt");
	while(!in.eof())
		{
			cout<<f<<"\t"<<c<<"\n";
			char a;
			bool stra1=false,flu1=false,stra2=false,flu2=false;
			int freq1[13]={0},freq2[13]={0},su1[4]={0},su2[4]={0},high1=0,high2=0,low1=14,low2=14,hand1[5],hand2[5],ic1=0,ic2=0;
			map <char,int> m1,m2,n1,n2;
			for (int i=0;i<5;i++)
				{
					in.get(a);
					if (int(a)<=57){freq1[int(a)-49]++;hand1[i]=int(a)-48;}
					else if (a=='T'){freq1[9]++;hand1[i]=9;}
					else if (a=='J'){freq1[10]++;hand1[i]=10;}
					else if (a=='Q'){freq1[11]++;hand1[i]=11;}
					else if (a=='K'){freq1[12]++;hand1[i]=12;}
					else {freq1[0]++;hand1[i]=13;}
					if (hand1[i]>high1)
						high1=hand1[i];
					if (hand1[i]<low1)
						low1=hand1[i];
					if (m1.find(a)==m1.end())
		        {
		        m1[a]=1;
		        ic1++;
		        }
		      else
		        m1[a]++;
					in.get(a);
					if (n1.find(a)==n1.end())
		        n1[a]=1;
		      else
		        n1[a]++;
					in.get(a);
				}
			for (int i=0;i<5;i++)
				{
					in.get(a);
					if (int(a)<=57){freq2[int(a)-49]++;hand2[i]=int(a)-48;}
					else if (a=='T'){freq2[9]++;hand2[i]=9;}
					else if (a=='J'){freq2[10]++;hand2[i]=10;}
					else if (a=='Q'){freq2[11]++;hand2[i]=11;}
					else if (a=='K'){freq2[12]++;hand2[i]=12;}
					else {freq2[0]++;hand2[i]=13;}
					if (hand2[i]>high2)
						high2=hand2[i];
					if (hand2[i]<low2)
						low2=hand2[i];
					if (m2.find(a)==m2.end())
	          {
	          ic2++;
	          m2[a]=1;
	          }
	        else
	          m2[a]++;
					in.get(a);
					if (n2.find(a)==m2.end())
		        n2[a]=1;
		      else
		        n2[a]++;
					in.get(a);
				}
		map <char,int>::iterator itn1=n1.begin(),itn2=n2.begin(),itm1=m1.begin(),itm2=m2.begin();
		c++;
		f++;


		//royal flush and straight flush
		int temp1=0,temp2=0;
		if (itn1->second==5)
			{
			flu1=true;
			if (freq1[0]==1 && freq1[1]==1 && freq1[2]==1 && freq1[3]==1 && freq1[4]==1)
				{
				temp1=5;
				stra1=true;
				}
			else if(high1-low1==4)
				{
				temp1=high1;
				stra1=true;
				if (low1==9)
					continue;
				}
			}
		if (itn2->second==5)
			{
			flu2=true;
			if (freq2[0]==1 && freq2[1]==1 && freq2[2]==1 && freq2[3]==1 && freq2[4]==1)
				{
				temp2=5;
				stra2=true;
				}
			else if(high2-low2==4)
				{
				temp2=high2;
				stra2=true;
				if (low2==9)
					{
					c--;
					continue;
					}
				}
			}
			if (temp1!=0 && temp2!=0)
				if (temp2>temp1)
				{
					{
						c--;
					}
				continue;
				}


		//4 of a kind
		temp1=0;temp2=0;
		if (freq1[0]==4)
			{
			cout<<c<<"\n";
			temp1=13;
			continue;
			}
		if (freq2[0]==4)
			{
			cout<<c<<"\n";
			temp2=13;
			c--;
			continue;
			}
		for (int i=1;i<13;i++)
			{
			if (freq1[i]==4)
				temp1=i;
			else if (freq2[i]==4)
				temp2=i;
			}
		if(temp1>temp2)
			{
			continue;
			}
		else if (temp2>temp1)
			{
				c--;
				continue;
			}


		// full house
		temp1=0;temp2=0;
		if (freq1[0]==3)
			{
			int flag=0;
			for (int i=1;i<13;i++)
				if (freq1[i]==2)
					{
					temp1=13;
					continue;
					}
			}
		if (freq2[0]==3)
			{
			int flag=0;
			for (int i=1;i<13;i++)
				if (freq2[i]==2)
					{
					temp2=13;
					c--;
					continue;
					}
			}
		for (int j=1;j<13;j++)
			{
				if (freq1[j]==3)
					{
					int flag=0;
					for (int i=0;i<13;i++)
						if (freq1[i]==2)
							{
							temp1=j;
							break;
							}
					}
			}
		for (int j=1;j<13;j++)
			{
				if (freq2[j]==3)
					{
					int flag=0;
					for (int i=0;i<13;i++)
						if (freq2[i]==2)
							{
							temp2=j;
							break;
							}
					}
			}
		if (temp1>temp2)
			continue;
		else if (temp1<temp2)
			{
			c--;
			continue;
			}


		//flush
		if (flu1 && !flu2)
				continue;
		else if (!flu1 && flu2)
				{
				c--;
				continue;
				}
		else if (flu1 && flu2)
			{
			if (high1>high2)
				continue;
			else
				{
				c--;
				continue;
				}
			}

		
		//straight
		if (ic1==5 || ic2==5)
		{
		temp1=0;temp2=0;
		stra1=false;stra2=false;
		if (freq1[0]==1 && freq1[1]==1 && freq1[2]==1 && freq1[3]==1 && freq1[4]==1)
			{
			temp1=5;
			stra1=true;
			}
		else if(high1-low1==4)
			{
			temp1=high1;
			stra1=true;
			if (low1==9)
				continue;
			}
		if (freq2[0]==1 && freq2[1]==1 && freq2[2]==1 && freq2[3]==1 && freq2[4]==1)
			{
			temp2=5;
			stra2=true;
			}
		else if(high2-low2==4)
			{
			temp2=high2;
			stra2=true;
			if (low2==9)
				{
				c--;
				continue;
				}

			}
		if (temp2>temp1)
			{
			c--;
			continue;
			}
		else if (temp1>temp2)
			continue;
		}
		


		//three of a kind
		temp1=0;temp2=0;
		if (freq1[0]==3)
				continue;
		if (freq2[0]==3)
			{
			c--;
			continue;
			}
		for (int i=1;i<13;i++)
			{
			if (freq1[i]==3)
				temp1=i;
			if (freq2[i]==3)
				temp2=i;
			}
		if (temp1>temp2)
			continue;
		else if (temp2>temp1)
			{
			c--;
			continue;
			}




		//two pairs
		int t1[2]={0},t2[2]={0},top1=0,top2=0;
		if (ic1==3 && ic2>3)
			continue;
		else if (ic1>3 && ic2==3)
			{
			c--;
			continue;
			}
		else if (ic1==3 && ic2==3)
		 	{
			int a1=0,a2=0;
			if (freq1[0]==2)
				{
				t1[a1]=13;
				a1++;
				}
			if (freq2[0]==2)
				{
				t2[a2]=13;
				a2++;
				}
			for (int i=12;i>=1;i--)
				{
				if (freq1[i]==1)
					top1=i;
				if (freq2[i]==1)
					top2=i;
				if (freq1[i]==2)
					{
					t1[a1]=i;
					a1++;
					}
				if (freq2[i]==2)
					{
					t2[a2]=i;
					a2++;
					}
				}
			if (t1[0]>t2[0])
				continue;
			else if (t2[0]>t1[0])
				{
				c--;
				continue;
				}
			else if(t1[1]>t2[1])
				continue;
			else if (t1[2]>t1[1])
				{
					c--;
					continue;
				}
			else if (top1>top2)
				continue;
			else
				{
				c--;
				continue;
				}
			}

	 
	 // One pair
	 if (ic1<ic2)
	 		continue;
	 else if (ic2<ic1)
	 		{
			c--;
			continue;
		  }
	 else if (ic1==4 && ic2==4)
	 	{
		//cout<<"a";
		int rest1[3]={0},rest2[3]={0},a1=0,a2=0;
	 	temp1=0;temp2=0;
	 	if (freq1[0]==2)
	 			{
				temp1=13;
				}
		if (freq2[0]==2)
				{
				temp2=13;
				}
		if (freq1[0]==1)
			{
			rest1[a1]=13;
			a1++;
			}
		if (freq1[0]==1)
			{
			rest2[a2]=13;
			a2++;
			}
		for (int i=12;i>=1;i--)
				{
				if (freq1[i]==2)
					temp1=i;
				if (freq2[i]==2)
					{
					temp2=i;
					}
				if (freq1[i]==1)
					{
					rest1[a1]=i;
					a1++;
					}
				if (freq2[i]==1)
					{
					rest2[a2]=i;
					a2++;
					}
				}
		if (temp1>temp2)
			continue;
		else if (temp2>temp1)
			{
			c--;
			continue;
			}
		else
			{
			if (rest1[0]>rest2[0])
					continue;
			else if (rest1[0]<rest2[0])
					{
					c--;
					continue;
					}
			else
					{
					if (rest1[1]>rest2[1])
							continue;
					else if (rest1[1]<rest2[1])
							{
							c--;
							continue;
							}
					else
							{
							if (rest1[2]>rest2[2])
								continue;
							else if (rest1[2]<rest2[2])
								{
								c--;
								continue;
								}
							}
					 }
				}
		}

		
		// High Card
		if (high1>high2)
			continue;
		else if (high2>high1)
			{
			c--;
			continue;
			}
		else
			{
			int arr1[5]={0},arr2[5]={0},a1=0,a2=0;
			if (freq1[0]==1)
				{
					arr1[a1]=13;
					a1++;
				}
			if (freq2[0]==1)
				{
					arr2[a2]=13;
					a2++;
				}
			for (int i=12;i>=1;i--)
				{
				if (freq1[i]==1)
					{
						arr1[a1]=i;
						a1++;
					}
				if (freq2[i]==1)
					{
						arr2[a2]=i;
						a2++;
					}
				}
			for (int i=0;i<5;i++)
				{
					if (arr1[i]>arr2[i])
						continue;
					else if (arr1[i]<arr2[i])
						{
						c--;
						continue;
					  }
				}
			}
	 }
	//cout<<"\n"<<c-1;
	in.close();
	cout<<endl;
	return 0;
	}
