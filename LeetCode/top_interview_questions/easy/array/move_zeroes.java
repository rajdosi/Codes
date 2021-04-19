/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
 */

class Solution {
    public void moveZeroes(int[] nums) {
        int zero_index = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                if (i < zero_index) {
                    zero_index = i;
                }
            }
            else {
                int temp = nums[i];
                nums[i] = nums[zero_index];
                nums[zero_index] = temp;
                zero_index++;
            }
        }
    }
}