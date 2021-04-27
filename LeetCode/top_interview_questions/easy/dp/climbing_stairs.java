/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
 */
class Solution {
    public int climbStairs(int n) {
        int prev = 1, curr = 1;
        while (n > 1) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
            n--;
        }

        return curr;
    }
}