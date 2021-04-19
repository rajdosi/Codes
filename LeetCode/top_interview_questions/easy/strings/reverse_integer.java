/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
 */

class Solution {
    public int reverse(int x) {
        
        int solution = 0;
        while (x != 0) {
            int temp = x % 10;
            x = x / 10;
            if (solution > Integer.MAX_VALUE/10 || (solution == Integer.MAX_VALUE/10 && temp > 7)) {
                return 0;
            }
            if (solution < Integer.MIN_VALUE/10 || (solution == Integer.MIN_VALUE/10 && temp < -8)) {
                return 0;
            }
            solution = solution * 10 + temp;
        }
        
        return solution;
    }
}