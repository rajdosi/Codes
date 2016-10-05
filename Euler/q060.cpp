#include<bits/stdc++.h>

using namespace std;

vector<bool> seivesPrimes(100000000);
int allprimes[1000000],prm[1000000],indexer=0,len=5;

void primes()
{
	memset(prm,0,sizeof(prm));
	for(int i=2;i<=1000;i++)
	{
		if(prm[i] == false){
			allprimes[indexer++] = i;
			for(int j=i+i;j<1000000;j+=i){
				prm[j] = true;
			}
		}
	}
	for(int i=1001;i<1000000;i++){
		if(prm[i] == false)
			allprimes[indexer++] = i;
	}
}

void shifter(int *ptr,int peak){
	ptr[0] = 0;
	for(int i=1;i<peak;i++){
		ptr[i] = ptr[i-1]+1;
	}
}

void next_combination(int *ptr){
	bool flag = false;
	for(int i=0;i<len-1;i++){
		if(ptr[i]+1 != ptr[i+1]){
			ptr[i]++;
			flag = true;
			if(i!=0)
				shifter(ptr,i);
			break;
		}
	}
	if(flag == false){
		ptr[len-1]++;
		shifter(ptr,len-1);
	}
}

bool check(int *ptr){
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++){
			char str[10];
			int number;
			sprintf(str,"%d%d",allprimes[ptr[i]],allprimes[ptr[j]]);
			number = atoi(str);
			if(prm[number])
				return false;
			sprintf(str,"%d%d",allprimes[ptr[j]],allprimes[ptr[i]]);
			number = atoi(str);
			if(prm[number])
				return false;
		}
	}
	return true;
}

void fillPrimes() {
	seivesPrimes[0] = seivesPrimes[1] = false;
	for (long i = 2; i < 100000000; i++)
	{
		seivesPrimes[i] = true;
	}

	for (long long i = 2; i < 100000000; i++)
	{
		if (seivesPrimes[i] != false)
		for (long long j = i*2; j < 100000000; j=j+i)
			seivesPrimes[j] = false;
	}
}

int main()
{
	cout<<seivesPrimes.max_size();
	fillPrimes();
	
	return 0;
}