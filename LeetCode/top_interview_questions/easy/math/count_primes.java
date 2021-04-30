/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
 */
class Solution {
    public int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        
        boolean[] seives = new boolean[n];
        for (int i = 2; i*i < n; i++) {
            if (seives[i]) {
                continue;
            }
            for (int j = i * i; j < n ;j += i) {
                seives[j] = true;
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!seives[i]) {
                count++;
            }
        }

        return count;
    }
}