/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/
 */
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0 || prices.length == 1) {
            return 0;
        }
        
        int answer = 0;
        int transaction = 0;
        
        for (int i = 1; i < prices.length; i++) {
            transaction += prices[i] - prices[i - 1];
            
            if (transaction < 0) {
                transaction = 0;
            }
            
            answer = Math.max(answer, transaction);
        }
        
        return answer;
    }
}