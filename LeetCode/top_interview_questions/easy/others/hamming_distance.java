/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/
 */
class Solution {
    public int hammingDistance(int x, int y) {
        int xor = x ^ y;
        int answer = 0;
        
        while (xor != 0) {
            answer += (xor & 1);
            
            xor >>= 1;
        }
        
        return answer;
    }
}