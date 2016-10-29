# include <bits/stdc++.h>
using namespace std;
vector<int> dp(121);

void initializeDP() {
	dp[0] = 0;
	dp[10] = 1;
	for (int i=1;i<10;i++)
		dp[i] = -1;

	for (int i=11; i<121 ;i++){
		if (i%2 == 1)
			dp[i] = -1;
		else if (i%12 == 0)
			dp[i] = i / 12;
		else if (dp[i-12] != -1)
			dp[i] = dp[i-12] + 1;
		else if (dp[i-10] != -1)
			dp[i] = dp[i-10] + 1;
		else
			dp[i] = -1;	
	}
}

int main() {
	initializeDP();
	// for (int i=0;i<121;i++)
	// 	cout<<i<<"\t"<<dp[i]<<"\n";
	int t;
	cin>>t;

	while (t--) {
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}