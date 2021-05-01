/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/601/
 */
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalTriangle = new ArrayList<>();
        
        List<Integer> lvl1 = new ArrayList<>();
        lvl1.add(1);
        pascalTriangle.add(lvl1);
        
        for (int i = 1; i < numRows; i++) {
            List<Integer> lvl = new ArrayList<>();
            lvl.add(1);
            for (int j = 1; j < i; j++) {
                lvl.add(pascalTriangle.get(i-1).get(j-1) + pascalTriangle.get(i-1).get(j));
            }

            lvl.add(1);
            pascalTriangle.add(lvl);
        }
        
        return pascalTriangle;
    }
}