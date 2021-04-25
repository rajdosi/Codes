/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
 */

class QueueSolution {
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(root);
        
        while (!q.isEmpty()) {
            TreeNode t1 = q.poll();
            TreeNode t2 = q.poll();
            
            if (t1 == null && t2 == null) {
                continue;
            }
            
            if (t1 == null || t2 == null) {
                return false;
            }
            
            if (t1.val != t2.val) {
                return false;
            }
            
            q.add(t1.left);
            q.add(t2.right);
            q.add(t1.right);
            q.add(t2.left);
        }
        
        return true;
    }
}

class RecursiveSolution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        return validate(root.left, root.right);
    }
    
    private boolean validate(TreeNode left, TreeNode right) {
        if (left == null && right == null) {
            return true;
        }
        
        if (left == null || right == null) {
            return false;
        }
        
        if (left.val != right.val) {
            return false;
        }
        
        return validate(left.left, right.right) && validate(left.right, right.left);
    }
}

class StackSolution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        
        Deque<TreeNode> leftStack = new ArrayDeque<>();
        Deque<TreeNode> rightStack = new ArrayDeque<>();
        
        TreeNode left = root.left;
        TreeNode right = root.right;

        while (!leftStack.isEmpty() || left != null || right != null) {
            while (left != null) {
                leftStack.push(left);
                left = left.left;
            }
            
            while (right != null) {
                rightStack.push(right);
                right = right.right;
            }
            
            if (leftStack.size() != rightStack.size()) {
                return false;
            }
            
            right = rightStack.pop();
            left = leftStack.pop();
            
            if (right.val != left.val) {
                return false;
            }
            
            left = left.right;
            right = right.left;
        }
        
        return true;
    }
}