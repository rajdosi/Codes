# include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(10000);

void initializeDP() {
	dp[0].push_back(1);

	for (int i=1;i<1000;i++){
		dp[i].push_back(1);
		for (int j=1;j<i;j++) {
			dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
		}
		dp[i].push_back(1);
	}
}

int main() {

	initializeDP();

	return 0;
}