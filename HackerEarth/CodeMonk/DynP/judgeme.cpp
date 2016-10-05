# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	int i=1;
	cin>>t;
	while (t--) {
		long arr_len;
		cin>>arr_len;
		vector<long long> judges(arr_len),dp(arr_len);
		for (long i=0;i<arr_len;i++) 
			cin>>judges[i];

		dp[arr_len-1] = judges[arr_len-1];
		if (arr_len != 1) {
			dp[arr_len-2] = max(dp[arr_len-1], judges[arr_len-2]);
			for (long i=arr_len-3; i>=0; i--) {
				dp[i] = dp[i+2] + judges[i];
				dp[i] = max (dp[i], dp[i+1]);
			}
		}

		cout<<"Case "<<i<<": "<<dp[0]<<endl;
		i++;
		
	}
	return 0;
}