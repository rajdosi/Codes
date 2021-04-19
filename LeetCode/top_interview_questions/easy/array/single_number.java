/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
 */

class Solution {
    public int singleNumber(int[] nums) {
        int a = 0;
        for (int i = 0; i < nums.length; i++) {
            a ^= nums[i];
        }   
        return a;
    }
}