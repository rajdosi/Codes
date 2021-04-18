/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
 */

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Integer>[] rowSet = new HashSet[9];
        Set<Integer>[] columnSet = new HashSet[9];
        Set<Integer>[] boxSet = new HashSet[9];
        
        for (int i = 0; i < 9; i++) {
            rowSet[i] = new HashSet<Integer>();
            columnSet[i] = new HashSet<Integer>();
            boxSet[i] = new HashSet<Integer>();
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char entry = board[i][j];
                if (entry == '.') {
                    continue;
                }
                
                int entryValue = (int) entry;
                int k = (i/3) * 3 + j/3;
                
                if (rowSet[i].contains(entryValue) || columnSet[j].contains(entryValue) || boxSet[k].contains(entryValue)) {
                    return false;
                }
                
                rowSet[i].add(entryValue);
                columnSet[j].add(entryValue);
                boxSet[k].add(entryValue);
            }
        }
        
        return true;
    }
}