# include <bits/stdc++.h>
using namespace std;

long long repetitiveCombination(long n, long k) {
	long long ans = 1;

	if (k == 0 || n == k) {
		return 1;
	}
	else {
		if (k > n/2)
			k = n-k;
		for (long i=0;i<k;i++) {
			ans *= n-i;
			ans /= i+1;
		}
	return ans;
	}
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		long n,k;
		cin>>n>>k;

		cout<<repetitiveCombination(n-1,k-1)<<endl;
	}

	return 0;
}