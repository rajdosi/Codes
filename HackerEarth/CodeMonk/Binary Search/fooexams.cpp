# include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while (t--){
		
		bool flag = false;

		long max = 1000000;
		long min = 0;
		long mid = (max + min)>>2;

		unsigned long long A,B,C,D,K,fot_min,fot_mid,fot_max; 

		cin>>A>>B>>C>>D>>K;

		while(min!=mid) {
			fot_mid = A * pow(mid,3) + B * pow (mid,2) + C * mid + D;

			if (fot_mid == K)
				break;
			else if (fot_mid < K) {
				min = mid;
				mid = (min + max)>>2; 
			}
			else {
				max = mid;
				mid = (min + max)>>2; 
			}
		}

		cout<<mid<<endl;
	}

	return 0;
}