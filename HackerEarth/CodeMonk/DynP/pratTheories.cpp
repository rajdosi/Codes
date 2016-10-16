# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while (t--) {
		long n,t_low,t_high;
		map<long,long> startToFreqMap;
		cin>>n;
		for (long i=0;i<n;i++) {
			cin>>t_low>>t_high;
			startToFreqMap[t_low]++;
			startToFreqMap[t_high]--;
		}

		long maxx = INT_MIN,sol=0;
		for (map<long,long>::iterator it=startToFreqMap.begin(); it != startToFreqMap.end(); it++) {
			sol += it->second;
			maxx = max(sol,maxx);
		}
		cout<<maxx<<endl;
	}
	return 0;
}