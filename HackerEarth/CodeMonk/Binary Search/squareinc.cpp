# include <bits/stdc++.h>
using namespace std;

int main() {

	long tran;
	int val;
	cin>>tran;
	long long worth[100001] = {0};

	for (long i=1; i<tran+1; i++){
		cin>>val;
		worth[i] = worth[i-1] + val;
	}

	/**for (long i=1; i<tran+1; i++){	
		cout<<worth[i];
	}*/

	long query;
	cin>>query;

	while(query--){
		long long target;
		cin>>target;

		long high,low = 1,mid;
		high = tran;
		mid = (high + low)>>1;

		if (worth[high] < target)
			cout<<"-1"<<endl;
		else if (worth[low] >= target)
			cout<<low<<endl;
		else {
			bool flag = false;
			while (low!=mid) {

				if (worth[mid] == target){
					cout<<mid<<endl;
					flag = true;
					break;
				}
				else if (worth[mid] < target) {
					low = mid; 
					mid = (low + high)>>1;
				}
				else {
					high = mid;
					mid = (low + high)>>1;
				}
			}		
			if(!flag)
				cout<<mid+1<<endl;
		}		
	}

	return 0;
}