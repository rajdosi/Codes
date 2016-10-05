# include<bits/stdc++.h>
using namespace std;

int main() {
	int n_arr,query;
	cin>>n_arr>>query;
	long long A[100000],B[100000],dp1[100000]={0},dp2[100000]={0};

	// Getting arrays
	for (int i=0; i<n_arr; i++) {
		cin>>A[i];
	}
	for (int i=0; i<n_arr; i++) {
		cin>>B[i];
		if (i%2 == 0){
			dp1[i+1] = dp1[i] + A[i];
			dp2[i+1] = dp2[i] + B[i]; 
		}
		else {
			dp1[i+1] = dp1[i] + B[i];
			dp2[i+1] = dp2[i] + A[i];
		}
	}

	while(query--) {
		int arrSel, left, right;
		cin>>arrSel>>left>>right;
		if (arrSel == 1) {
			if (left%2 == 1)
				cout<<dp1[right] - dp1[left-1]<<endl;
			else
				cout<<dp2[right] - dp2[left-1]<<endl;
		}
		else if (arrSel == 2) {
			if (left%2 == 1)
				cout<<dp2[right] - dp2[left-1]<<endl;
			else
				cout<<dp1[right] - dp1[left-1]<<endl;
		}
	}

	return 0;
}