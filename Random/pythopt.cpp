# include <bits/stdc++.h>
using namespace std;

// Highly optimized pythogras triplet finder

unsigned gcd(unsigned u, unsigned v) 
	{
    while (v!=0) 
    	{
        unsigned r=u%v;
        u=v;
        v=r;
    	}
    return u;
	}

int main()
	{
	int pMax=0,tMax=0;
	int m=0,k=0; 
	for(int s=1;s<=1000;s++) 
		{
   		int t=0;
    	int mlimit=(int)sqrt(s/2);
    	for (m=2;m<=mlimit;m++) 
    		{
        	if ((s/2)%m==0) 
        		{ // m found
            	if (m%2==0) 
            		{	 // ensure that we find an odd number for k
                	k=m+1;
            		} 
            	else 
            		{
                	k=m+2;
            		}
           		while (k<2*m && k<=s/(2*m)) 
            		{
                 	if (s/(2*m)%k==0 && gcd(k,m)==1) 
                 		{
                     	t++;
                 		}
                 	k += 2;
             		}
         		}
     		}
     	if (t > tMax) 
     		{
        	tMax = t;
        	pMax = s;
    		}
		}
	cout<<tMax<<"\t"<<pMax<<"\n";
	return 0;
	}