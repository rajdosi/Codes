#include<bits/stdc++.h>
using namespace std;

int main(){
	string streakContinue = "The streak lives still in our heart!";
	string streakEnd = "The streak is broken!"; 
	string n21 = "21"; 
	int t;
	cin>>t;

	while(t--) {
		long int a;
		cin>>a;
		string a_str = std::to_string(a);
		if (a%21 == 0){
			cout<<streakEnd<<endl;
		}
		else if (a_str.find(n21) != std::string::npos) {
			cout<<streakEnd<<endl;
		}
		else {
			cout<<streakContinue<<endl;
		}
	}

	return 0;
}