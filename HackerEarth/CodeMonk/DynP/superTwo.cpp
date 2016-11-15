# include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(10001);
long long mod = 1000000007;

void initialize_dp() {
	for (int i=0;i<10;i++)
		dp[1].push_back(1);

	for (int i=2;i<10001;i++) {
		dp[i].push_back(1);
		for (int j=1;j<10;j++)
			dp[i].push_back((dp[i-1][j-1] % mod + dp[i-1][j] % mod) % mod);
	}
}

void display_dp() {
	for (int i=1;i<=10;i++) {
		for (int j=0;j<10;j++)
			cout<<dp[i][j]<<"\t";
		cout<<endl;
	}
}

int main() {
 	
 	initialize_dp();
 	display_dp();

 	int t;
 	cin>>t;

 	while (t--) {
 		int n,p;
 		cin>>n>>p;
 		cout<<endl<<dp[n][p-1];
 	}

	return 0;
}