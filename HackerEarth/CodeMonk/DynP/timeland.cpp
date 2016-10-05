# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		long n,k;
		cin>>n>>k;
		vector<long long> num_arr(n),dp(n);
		for (long i=0;i<n;i++)
			cin>>num_arr[i];

		dp[n-1] = num_arr[n-1];
		for (long i=n-2;i>=n-k-1;i--)
			dp[i] = max(num_arr[i],dp[i+1]);

		for (long i=n-k-2;i>=0;i--) {
			dp[i] = max(num_arr[i] + dp[i+k+1],max(num_arr[i],dp[i+k+1]));
			dp[i] = max(dp[i],dp[i+1]);
		}

		long long ans = dp[0]<0?0:dp[0];
		cout<<ans<<endl;
	}

	return 0;
}