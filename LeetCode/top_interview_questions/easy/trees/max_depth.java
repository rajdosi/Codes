
/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
 */
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}

class Solution2 {
    
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        TreeNode separator = new TreeNode(-1);
        Queue<TreeNode> queue = new LinkedList<>();
        
        int count = 1;
        queue.add(root);
        queue.add(separator);
        
        while (true) {
            TreeNode curr = queue.remove();
            while (curr != separator) {
                if (curr.left != null) {
                    queue.add(curr.left);
                }
                
                if (curr.right != null) {
                    queue.add(curr.right);
                }
                    
                curr = queue.remove();
            }
            
            if (queue.isEmpty()) {
                return count;
            }
            
            count++;
            queue.add(separator);
        }
    }
}