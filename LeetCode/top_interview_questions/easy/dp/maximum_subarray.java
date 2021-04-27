/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/566/
 */
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        
        int answer = Integer.MIN_VALUE;
        int localMaxima = 0;
        for (int i = 0; i < nums.length; i++) {
            localMaxima += nums[i];            
            answer = Math.max(answer, localMaxima);

            if (localMaxima < 0) {
                localMaxima = 0;
            }
        }
        
        return answer;
    }
}