/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
 */

class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
    }
}