# include <bits/stdc++.h> 
using namespace std;

int main () {
	string yes="YES";
	string no="NO";
	int t;
	cin>>t;

	while (t--){
		string a;
		int i = 0;
		bool flag = false;
		cin>>a;
		int j = a.length()-1;

		for (; i <= a.length()/2; i++, j--) {
			if (a[i]==a[j]) {
				if ((a[i] == '8' || a[i] == '1' || a[i] == '0') )
					continue;
				else {
				cout<<no<<endl;
				flag = true;
				break;
				}
			}
			else {
				cout<<no<<endl;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout<<yes<<endl;
		}
	}
	return 0;
}