# include <bits/stdc++.h>
using namespace std;

vector<bool> seives(100005);
vector<long> primes;

void createSeive() {

	seives[0] = seives[1] = true;

	for (int i = 2; i<317; i++) {
		if (!seives[i]) {
			for (int j = i*2; j<100005; j=j+i) 
				seives[j] = true;
			}
	}

	int val = 0;
	for (int i=0;i<100005;i++) {
		if (!seives[i])
			val = i;
		primes.push_back(val);
	}
}

int main() {

	createSeive();

	long n;
	cin>>n;
	vector<long> problemPoints(n);
	long arr_val = (n-primes[n] == 0)?1:n-primes[n];
	vector<long long> sum(arr_val);
	
	for (long i=0;i<primes[n];i++) {
		cin>>problemPoints[i];
		sum[0] = sum[0] + problemPoints[i];
	}

	long long maximum = sum[0];
	for (int i=1; i<=n-primes[n];i++) {
		cin>>problemPoints[primes[n] + i - 1];
		sum[i] = sum[i-1] + problemPoints[primes[n] + i - 1] - problemPoints[i-1];
		maximum = max (sum[i], sum[i-1]);
	}

	cout<<maximum;

	return 0;
}