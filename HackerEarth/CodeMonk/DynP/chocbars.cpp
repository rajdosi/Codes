# include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string cream_arr;
		vector<long> dp(1000005);
		long longest_sequence=INT_MIN;
		cin>>cream_arr;
		for (long i = cream_arr.length()-1; i >= 2; i--) {
			if (cream_arr[i] != cream_arr[i-1] || cream_arr[i-1] != cream_arr[i-2])
				dp[i] = dp[i+3] + 3;	
			longest_sequence = max(longest_sequence, dp[i]);
		}
		cout<<cream_arr.length() - longest_sequence<<endl;
	}	
	return 0;
}