# include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	cin>>t;
	while(t--) {
		long longest_end = INT_MIN;
		long rope_length;
		cin>>rope_length;
		vector<long> upper(rope_length),lower(rope_length);
		for (long i=1; i<rope_length; i++) 
			cin>>upper[i];
		for (long i=1; i<rope_length; i++)
			cin>>lower[i];
		for (long i=1; i<rope_length; i++) {
			upper[i] = upper[i] + i; 
			lower[i] = lower[i] + i;
			longest_end = max(longest_end,max(upper[i],lower[i])); 
		}
		longest_end = max(longest_end,rope_length);
		cout<<longest_end<<endl;
	}
	return 0;
}
