# include <bits/stdc++.h>
using namespace std;

vector<bool> seives(40000);
vector<long> primes;


void calcSeives() {
	seives[0] = true;
	seives[1] = true;

	for (int i=2; i<200;i++) {
		if (!seives[i]) {
			for (int j= i*i ;j<40000;j=j+i)
				seives[j] = true;
			primes.push_back(i);
		}
	}

	for (int i = 200; i< 40000; i++)
		if (!seives[i]){
			primes.push_back(i);
		}
}

void calcExtendedSeives(long long a, long long b) {
	
	if(a<2) a=2;
	vector<bool> extendedSeives(b-a+1);

	for (long long i=0;primes[i]<=sqrt(b)+1;i++) {
		long long start = (primes[i]>=a)? primes[i]*2 : a + ((primes[i] - (a%primes[i]))%primes[i]);
		for (long long j=start; j<=b; j=j+primes[i])
			extendedSeives[j-a] = true;
	}

	for (long long i=a;i<=b;i++)
		if (!extendedSeives[i-a])
			cout<<i<<endl;
}

int main() {

	calcSeives();

	int t;
	cin>>t;
	while(t--) {
		long long a,b;
		cin>>a>>b;
		if (b<=40000) {
			for (long i=a;i<=b;i++){
				if (!seives[i])
					cout<<i<<endl;
			}
		}
		else {
			calcExtendedSeives(a,b);
		}

		cout<<endl;
	}

	return 0;
}