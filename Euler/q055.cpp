# include <bits/stdc++.h>
using namespace std;

int *mark=new int[10000]; 
vector <int> V,L;

bool ispal(int *a,int s)
	{
	for (int i=0;i<s/2;i++)
		{	
		if(a[49-i]!=a[50-s+i])
			return false;
		}
	return true;
	}


int main()
	{
	int start=1;
	int size=1;
	int mc=0;
	while (start<10000)
		{
		for (int i=start;i<(start*10);i++)
			{
			if (mark[i]==0)
				{
				//cout<<i<<"\t";
				int n=i;
				int num1[50]={0},num2[50]={0};
				int count=0;
				for (int j=0;j<size;j++)
					{
					num1[49-j]=n%10;
					n=n/10;
					}
				int s=size;
				int flag=0;
				while (count<50)
					{
					count++;
					if (ispal(num1,s))
						{
						for (int k=0;k<V.size();k++)
							mark[V[k]]=2;
						V.clear();
						if (s>4)
							{
							flag=1;
							break;
							}
						}
					if (s<5)
						{
						int temp=0;
						int tmp2=0;
						for (int k=0;k<s;k++)
							{
							temp=temp+(pow(10,k)*num1[49-k]);
							tmp2=tmp2+(pow(10,k)*num1[50-s+k]);
							}
						//cout<<temp<<"\t";
						if (mark[temp]==0)
							{
							V.push_back(temp);
							if (temp!=tmp2)
								V.push_back(tmp2);
							}
						count=0;
						}
					for (int j=0;j<s;j++)
						num2[50-s+j]=num1[49-j];
					int carry=0;
					for (int j=0;j<s;j++)
						{
						num1[49-j]=num1[49-j]+num2[49-j]+carry;
						if (num1[49-j]>=10)
							{
							carry=num1[49-j]/10;
							num1[49-j]=num1[49-j]%10;
							}
						else
							carry=0;
						} 
					if (carry>0)
						{
						num1[49-s]=1;
						s++;
						}
				 //    for (int k=0;k<s;k++)
				 // 		cout<<num1[50-s+k];
					// cout<<"\n";
					}
				if (flag==0 && V.size()!=0)
					{
					for (int k=0;k<V.size();k++)
						{
						if (mark[V[k]]==0)
							{
							mark[V[k]]=1;
							mc++;
							//cout<<V[k]<<"\t";	
							}
						}
					//cout<<endl;
					}
				}
			}
		start=start*10; 	
		size++;
		}
	// for (int i=0;i<L.size();i++)
	// 	cout<<L[i]<<endl;
	cout<<endl;
	cout<<mc;
	cout<<endl;
	return 0;
	}

			// cout<<i<<"\t";
			// for (int i=0;i<s;i++)
			//  	cout<<num1[50-s+i];
			// cout<<"\t";	
			// for (int i=0;i<size;i++)
			// 	cout<<num2[30-size+i];