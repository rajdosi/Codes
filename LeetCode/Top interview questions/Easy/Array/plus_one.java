/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
 */

class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] = digits[i] % 10;
        }
        
        if (carry == 1) {
            int[] answer = new int[digits.length + 1];
            answer[0] = 1;
            for (int i = 1; i <= digits.length; i++) {
                answer[i] = digits[i-1];
            }
            return answer;
        }
        else {
            return digits;
        }
    }
}