/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
 *
 * Method 1 - transpose matrix and reverse columns
 * Method 2 - Maintain 4 points -> left, right, top, bottom and use loop index to change values
 */

class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < (matrix.length/2); i++) {
            for (int j = i; j <= matrix.length - i - 2; j++) {
                int temp = matrix[i][j];

                matrix[i][j] = matrix[matrix.length - j - 1][i];
                matrix[matrix.length - j - 1][i] = matrix[matrix.length - i - 1][matrix.length - j - 1];
                matrix[matrix.length - i - 1][matrix.length - j - 1] = matrix[j][matrix.length - i - 1];
                matrix[j][matrix.length - i - 1] = temp;
            }
        }
    }
}