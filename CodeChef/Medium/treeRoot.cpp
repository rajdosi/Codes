# include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while (t--) {
		int nodes;
		cin>>nodes;
		int a,b;
		long long root=0;

		for (int i=0;i<nodes;i++) {
			cin>>a>>b;

			root += a - b;
		}

		cout<<root<<endl;
	}

	return 0;
}