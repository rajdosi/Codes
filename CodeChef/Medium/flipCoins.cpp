# include <bits/stdc++.h>
using namespace std;

long long segmentSize;

// long createSegmentTree(vector<long long> &st, long start, long end, long index) {
// 	if (start == end) {
// 		st[index] = 0;
// 	}
		
// }

long long query(vector<long long> &st, long left, long right) {
	return 0;
}

long long update(vector<long long> &st, long start, long end, long left, long right, long index) {

	if (left>end || right<start) 
		return 0;
	if (left == right) {
		st[index] = (st[index] == 0)?1:0;
		return st[index];
	}

	st[index] = update(st,start,end/2,left,right,index*2) + 
				update(st,end/2,end,left,right,index*2+1);
	return st[index];
}

void display_st(vector<long long> &st,long n) {
	for (int i=0;i<n-1;i++) {
		for (int j = 0; j < pow(2,i); j++)
			cout<<st[pow(2,i)+j]<<"\t";
		cout<<endl;
	}


}


int main() {
	long long n,q;
	cin>>n>>q;

	segmentSize = (2*n)-1;
	vector<long long> st(segmentSize);

	for (int i=0;i<q;i++) {
		long q_t,left,right;
		cin>>q_t>>left>>right;

		if (q_t == 1) {
			cout<<query(st,left,right)<<endl;
		}
		else if (q_t == 0) {
			update(st,0,n,left,right,0);
			display_st(st,n);
		}
	}


	return 0;
}