# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while (t--) {
		int arr_len;
		cin>>arr_len;
		vector<long long> num_arr(arr_len),dp(arr_len);

		for (int i=0; i<arr_len; i++) {
			cin>>num_arr[i];
			dp[i] = -1;
		}

		dp[arr_len-1] = num_arr[arr_len-1];
		dp[arr_len-2] = max(dp[arr_len-1], num_arr[arr_len-2]);
		for (int i=arr_len-3; i>=0; i--) {
			dp[i] = dp[i+2] + num_arr[i];
			dp[i] = max (dp[i], dp[i+1]);
		}

		cout<<endl<<endl<<dp[0]<<endl<<endl;
	}
	return 0;
}