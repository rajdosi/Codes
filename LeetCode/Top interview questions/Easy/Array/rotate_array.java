/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/ 
 */

class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length);
        reverse(nums, 0, k);
        reverse(nums, k, nums.length);
    }
    
    private void reverse(int[] nums, int start, int end) {
        for (int i = 0; i < (end-start)/2; i++) {
            int temp = nums[start + i];
            nums[start + i] = nums[end - 1 - i];
            nums[end - 1 - i] = temp;
        }
    }
}