# include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	vector<vector<long>> dp(3,vector<long>(1000000));
	cin>>n;
	dp[0][0] = n - 1;
	dp[1][0] = (n%2 == 0)? n/2:n;
	dp[2][0] = (n%3 == 0)? n/3:n;
	long i=1;
	for (;i<=n;i++){
		if (dp[0][i-1] == 1 || dp[1][i-1] == 1 || dp[2][i-1] == 1){
			cout<<"Total Iterations : "<<i<<endl;
			break;
		}

		dp[0][i] = min(min(dp[0][i-1] - 1, dp[1][i-1] - 1), dp[2][i-1] - 1 );
		dp[1][i] = min(min((dp[0][i-1]%2 == 0 )?dp[0][i-1]/2:dp[0][i-1],
			(dp[1][i-1]%2 == 0)?dp[1][i-1]/2:dp[1][i-1]),
			(dp[2][i-1]%2 == 0)?dp[2][i-1]/2:dp[2][i-1]);
		dp[2][i] = min(min((dp[0][i-1]%3 == 0)?dp[0][i-1]/3:dp[0][i-1],
			(dp[1][i-1]%3 == 0)?dp[1][i-1]/3:dp[1][i-1]),
			(dp[2][i-1]%3 == 0)?dp[2][i-1]/3:dp[2][i-1]);
	}

	long arr_size = i;
	vector<long> path(arr_size+1);
	path[arr_size] = 1;
	
	for (long i =arr_size-1; i>0 ; i--) {
		if (path[i+1] == dp[0][i]) {
			path[i] = path[i+1] + 1;
		} else if (path[i+1] == dp[1][i]) {
			path[i] = path[i+1] * 2;
		} else {
			path[i] = path[i+1] * 3;
		}
	}

	path[0] = n;
	cout<<"Path : ";
	for (long i = arr_size; i>=0 ; i--) {
		cout<< path[i] << "\t";
	}

	cout<<endl;
	return 0;
}