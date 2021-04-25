/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return prepareTree(nums, 0, nums.length - 1);  
    }
    
    private TreeNode prepareTree(int[] nums, int low, int high) {
        if (low > high) {
            return null;
        }
        
        int mid = (low + high)/2;
        TreeNode node = new TreeNode(nums[mid]);
        
        node.left = prepareTree(nums, low, mid - 1);
        node.right = prepareTree(nums, mid + 1, high);
        
        return node;
    }
}