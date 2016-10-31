# include <bits/stdc++.h>
using namespace std;

bool allNiners(string &str) {
	for (long i=0;i<str.length();i++) {
		if (str[i]!='9')
			return false;
	}
	return true;
}

void computeNextPalindrome(string &str) {
	long i,j, h_l = str.length()/2;	
	i =  h_l - 1;
	j = ((str.length() % 2) == 0 )? h_l: h_l + 1;

	while(i >= 0 && str[i] == str[j]){
		i--;j++;
	}

	bool middleIncrement = false;
	if (i<0 || str[i]<str[j])
		middleIncrement = true;

	while (i>=0) {
		str[j] = str[i]; 
		j++;i--;
	}

	if (middleIncrement) {
		int carry = 1;
		i = h_l - 1; 
		if (str.length()%2 == 1) {
			str[h_l] += carry;
			if (str[h_l] - '0' == 10) {
				str[h_l] = '0';
				carry = 1;
			}
			else
				carry = 0;
			j = h_l + 1;
		}
		else
			j = h_l;

		while (i>=0) {
			str[i] += carry;
			if (str[i] - '0' == 10) {
				str[i] = '0';
				carry = 1;
			}
			else
				carry = 0;
			str[j++] = str[i--];
		}
	}

	cout<<str<<endl;
}

void nextPalindrome(string &str) {
	if (allNiners(str)){
		cout<<"1";
		for (long i=0;i<str.length()-1;i++)
			cout<<"0";
		cout<<"1"<<endl;
	}
	else 
		computeNextPalindrome(str);
}


int main() {
	long t;
	cin>>t;
	cin.ignore();

	while (t--) {
		string str;
		getline(cin,str);
		nextPalindrome(str);
	}

	return 0;
}