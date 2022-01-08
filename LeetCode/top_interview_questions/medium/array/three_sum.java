/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
 */

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();
        if (nums == null || nums.length < 3) {
            return answer; 
        }
        
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length && nums[i] <= 0; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            Set<Integer> seen = new HashSet<>();
            for (int j = i + 1; j < nums.length; j++) {
                
                int complement = - nums[i] - nums[j];
                
                if (seen.contains(complement)) {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(nums[i]);
                    triplet.add(nums[j]);
                    triplet.add(complement);
                    answer.add(triplet);
                    
                    while (j+1 < nums.length && nums[j+1] == nums[j]) {
                        j++;
                    }
                    
                }
                
                seen.add(nums[j]);
            } 
        }
        
        return answer; 
    }
}