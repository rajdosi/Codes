# include <bits/stdc++.h>
using namespace std;

struct maxVariable{
	long max;
	vector<int> v;	

	maxVariable(){
		max = INT_MIN;	
	}
}maxVec;

int main() {
	int b_w = 1,g_w = 2*b_w;
	int n_lines,i=0;
	long long days[30]={0};
	cin>>n_lines;
	cin.ignore();		

	while(n_lines--) {	
		int weight;
		string msg;
		getline(cin,msg);

		if (msg[0] == 'G')
			weight = g_w;
		else
			weight = b_w;		
		
		for (int i = 2; i < msg.length(); i++){
			if (isdigit(msg[i])){
				long tens = 10;
				long numStr = (int)(msg[i]-'0');
				i++;
				while (isdigit(msg[i])){
					numStr = numStr * tens + (int)(msg[i]-'0');
					i++;
				}
				
				if (numStr <= 31) {
					days[numStr-1] += weight;
					if (days[numStr-1] > maxVec.max){
						maxVec.max = days[numStr-1];
						maxVec.v.clear();
						maxVec.v.push_back(numStr);
					}
					else if (days[numStr-1] == maxVec.max) {
						maxVec.v.push_back(numStr);
					}
				}
			}
		}
	}

	if (maxVec.v.size() >= 2 || maxVec.v.size() == 0) {
		for (int i=0; i<20 ;i++ )cout<"\n";
		cout<<"No Date";
	}
	else if (maxVec.v.front() == 19 || maxVec.v.front() == 20) {
		cout<<"Date";
	}
	else {
		cout<<"No Date";
	}

	return 0;
}