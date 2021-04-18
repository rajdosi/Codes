/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
 */

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
       
        for (int i = 0; i < nums.length; i++) {
            
            if (map.containsKey(nums[i])) {
                int[] answer = new int[2];
                answer[0] = map.get(nums[i]);
                answer[1] = i;
                return answer;
            }
            
            map.put(target - nums[i], i);
        }
        
        throw new RuntimeException("No solution");
    }
}