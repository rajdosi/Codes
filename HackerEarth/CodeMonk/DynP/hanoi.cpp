# include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<pair<long long, long long>> radiusHeightPairs;
		for (int i=0;i<n;i++) {
			
			long long rI,hI;
			cin>>rI>>hI;
			radiusHeightPairs.push_back(make_pair(rI,hI));
		}

		sort(radiusHeightPairs.begin(),radiusHeightPairs.end());
		vector<long long> dp(n);
		dp[0] = radiusHeightPairs[0].second;
		long long incrMax = dp[0];

		for (int i=1;i<n;i++) {
			dp[i] = radiusHeightPairs[i].second;
			for (int j=0;j<i;j++) {
				if (radiusHeightPairs[i].first > radiusHeightPairs[j].first && radiusHeightPairs[i].second > radiusHeightPairs[j].second) {
					dp[i] = max(dp[i], dp[j] + radiusHeightPairs[i].second);
				}
			}
			incrMax = max(incrMax, dp[i]);
		}

		cout<<incrMax<<endl;
	}

	return 0;
}
