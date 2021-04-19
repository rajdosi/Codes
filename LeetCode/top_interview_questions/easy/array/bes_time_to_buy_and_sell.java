/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
 */

class Solution {
    public int maxProfit(int[] prices) {
        int answer = 0;
        
        for (int i = 0; i < prices.length - 1; i++) {
            if (prices[i] < prices[i+1]) {
                answer = answer + prices[i+1] - prices[i];
            }
        }
        
        return answer;
    }
}