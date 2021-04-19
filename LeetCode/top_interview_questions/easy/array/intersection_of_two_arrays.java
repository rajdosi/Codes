/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
 */

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0;
        
        List<Integer> answer = new ArrayList<>();
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                answer.add(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        int[] intersection = new int[answer.size()];
        for (int k = 0; k < answer.size(); k++) {
            intersection[k] = answer.get(k);
        }
        
        return intersection;
    }
}