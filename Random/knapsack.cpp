#include <bits/stdc++.h>
using namespace std;

int optimal_weight(int W, vector<int> w) {
  //write your code here
    int current_weight = 0;
    int wsize = w.size();  
    vector<vector< int >> dp(wsize+1,vector<int>(W+1, 0)); 

    for (int i = 1; i <= wsize; i++) {
      for(int j = 0; j<= W;j++) {
        dp[i][j] = dp[i-1][j];
        if (j>=w[i-1]){
          dp[i][j] = max((w[i-1] + dp[i-1][j-w[i-1]]),dp[i][j]);          
         }       
       }
    }
    return dp[wsize][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}