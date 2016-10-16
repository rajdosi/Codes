# include <bits/stdc++.h>
using namespace std;

map<long long, long long> coinToMaxCoinsMap;

long long findOptimal(long long n) {
	if (n < 12) 
		return n;
	if (coinToMaxCoinsMap.find(n) != coinToMaxCoinsMap.end()) 
		return coinToMaxCoinsMap.find(n)->second;
	else {
		long long val = findOptimal(n/2) + findOptimal(n/3) + findOptimal(n/4);
		coinToMaxCoinsMap.insert(pair<long long, long long>(n,val));
		return coinToMaxCoinsMap.find(n)->second;
	}
}


int main() {

	long long n;
	
	while (scanf("%lld",&n) != EOF) {

		cout<<findOptimal(n)<<endl;
	}

	return 0;
}