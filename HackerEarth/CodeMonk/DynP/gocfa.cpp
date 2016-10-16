# include <bits/stdc++.h>
using namespace std;

int main() {

	long soilders, val = 1, loa;
	cin>>soilders;
	vector<long> arr(soilders),dp(soilders);
	cin>>arr[0];
	dp[0] = 1;

	for (long i=1;i<soilders;i++) {
		
		cin>>arr[i];
		if (arr[i] <= arr[i-1])
			dp[i] = 1;
		else
			dp[i] = dp[i-1] + 1;
	}

	loa = dp[soilders-1];
	for (long i=soilders-2;i>=0;i--) {
		if (arr[i]>arr[i+1] && dp[i]<=dp[i+1])
			dp[i] = dp[i+1] + 1;	
		loa += dp[i];
	}

	cout<<loa;

	return 0;
}