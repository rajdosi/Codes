/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValid(root, null, null);        
    }
    
    private boolean isValid(TreeNode node, TreeNode high, TreeNode low) {
         if (node == null) {
            return true;
        }
        
        boolean isValid = isValid(node.left, node, low) && isValid(node.right, high, node);    
        if (!isValid) {
            return false;
        }
        
        if ((high == null || node.val < high.val) 
            && (low == null || node.val > low.val)) {
            return true;
        }
        
        return false;
    }
}

class Solution2 {
    private Integer prev = null;
    
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        if (!isValidBST(root.left)) {
            return false;
        }
        
        if (prev != null && root.val <= prev) {
            return false;
        }
        
        prev = root.val;
        return isValidBST(root.right);
    }
}

class Solution3 {    
    public boolean isValidBST(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>(); 
        Integer prev = null;

        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            
            root = stack.pop();
            
            if (prev != null && root.val <= prev) {
                return false;
            }
            
            prev = root.val;
            root = root.right;
        }
        
        return true;
    }
}
