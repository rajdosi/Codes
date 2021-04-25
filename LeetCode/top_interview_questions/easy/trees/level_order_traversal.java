/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
 */

class QueueSolution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<>();
        int level = 0;
        
        if (root == null) {
            return levels;    
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        
        while(!q.isEmpty()) {
            List<Integer> currentLevel = new ArrayList<>();
            int j = q.size();
            
            for (int i = 0; i < j; i++) {                
                TreeNode curr = q.poll();       
                currentLevel.add(curr.val);
                if (curr.left != null) {    
                    q.add(curr.left);
                }
                if (curr.right != null) {    
                    q.add(curr.right);
                }
            }
            
            level++;
            levels.add(currentLevel);
        }
        
        return levels;
    }
}

class RecursiveSolution {
    List<List<Integer>> levelsStore; 
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        levelsStore = new ArrayList<>();
        if (root == null) {
            return levelsStore;
        } 

        prepare(root, 1);
        return levelsStore;
    }
    
    private void prepare(TreeNode node, Integer level) {
        if (node == null) {
            return;
        }
        
        if (levelsStore.size() < level) {
            List<Integer> singleLevel = new ArrayList<>();
            singleLevel.add(node.val);
            levelsStore.add(singleLevel);
        } else {
            levelsStore.get(level - 1).add(node.val);
        }
        
        prepare(node.left, level + 1);
        prepare(node.right, level + 1);
    }
}