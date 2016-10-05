# include <bits/stdc++.h>
using namespace std;

bool *seive=new bool[100000000];
vector <long int> V;

int main()
	{
	seive[0]=seive[1]=1;
	for (long int i=2;i<10000;i++)
		{
		if (seive[i]==false)
			{
			for (long int j=i*i;j<100000000;j=j+i)
				seive[j]=true;
			}
		}	
	bool found=false;
	int i,j;
	for (i=10;i<100;i++)
		{
		int num[2];
		num[1]=i%10;
		num[0]=(i/10)%10;
		int p[4][5]={num[0],0,0,0,num[1],
					 0,0,0,num[0],num[1],
					 0,num[0],0,0,num[1],
					 0,0,num[0],0,num[1]};
		int cnt[4]={0,0,0,0};	
		//cout<<"\n"<<num[0]<<"\t"<<num[1]<<"\n";
		for (j=0;j<10;j++)
			{
			for (int k=0;k<4;k++)
				{
				if (p[k][0]==0 && j==0)
					continue;
				long int temp=0;
				for (int l=4;l>=0;l--)
					{
					if (p[k][l]==0)
						{
						p[k][l]=j;
						temp=temp+(p[k][l]*pow(10,4-l));
						p[k][l]=0;
						}
					else
						temp=temp+(p[k][l]*pow(10,4-l));
					}
				//cout<<"\t"<<temp;
				if (seive[temp]==false)
					cnt[k]=cnt[k]+1;
				}
			} 
		for (j=0;j<4;j++)
			{
			//cout<<"\t"<<cnt[j]<<"";
			if (cnt[j]==7)
				{
				found==true;
				break;
				}		
			}
		}
	if (found==true)
		exit(0);
	for (int i=100;i<1000;i++)
		{
		int num[3];
		found=true;
		num[2]=i%10;
		num[1]=(i/10)%10;
		num[0]=((i/10)/10)%10;
		int p[10][6]={num[0],num[1],0,0,0,num[2],
					  num[0],0,num[1],0,0,num[2],
					  num[0],0,0,num[1],0,num[2],
					  num[0],0,0,0,num[1],num[2],
				 	  0,num[0],num[1],0,0,num[2],
					  0,num[0],0,num[1],0,num[2],
					  0,num[0],0,0,num[1],num[2],
					  0,0,num[0],num[1],0,num[2],
					  0,0,num[0],0,num[1],num[2],
					  0,0,0,num[0],num[1],num[2]};
		int cnt[10]={0};	
		//cout<<num[0]<<"\t"<<num[1]<<"\t"<<num[2]<<"\n";
		for (j=0;j<10;j++)
			{
			for (int k=0;k<10;k++)
				{
				if (p[k][0]==0 && j==0)
					continue;				
				long int temp=0;
				for (int l=5;l>=0;l--)
					{
					if (p[k][l]==0)
						{
						p[k][l]=j;
						temp=temp+(p[k][l]*pow(10,5-l));
						p[k][l]=0;
						}
					else	
						temp=temp+(p[k][l]*pow(10,5-l));
					}
				if (seive[temp]==false)
					cnt[k]++;
				}
			} 
		for (j=0;j<10;j++)
			{
			//cout<<"\t"<<cnt[j];
			if (cnt[j]==8)
				{
				int k=1;
				while (found)
					{
					long int temp=0;
					for (int l=5;l>=0;l--)
						{
						if (p[j][l]==0)
							{
							p[j][l]=k;
							temp=temp+(p[j][l]*pow(10,5-l));
							p[j][l]=0;
							}
						else	
							temp=temp+(p[j][l]*pow(10,5-l));
						}
					if (seive[temp]==false)
						{
						cout<<temp;
						exit(0);	
						}
					k++;
					}
				}		
			}
		}



	// for (int i=0;i<100000000;i++)
	// 	{
	// 	if (seive[i]==false)
	// 		V.push_back(i);
	// 	}
	cout<<endl;
	return 0;
	}