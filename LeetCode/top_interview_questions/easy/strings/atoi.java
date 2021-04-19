/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/
 */

class Solution {
    public int myAtoi(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }

        if (i >= s.length()) {
            return 0;
        }
        

        boolean isPositive = true;
        if (s.charAt(i) == '+') {
            i++;
        }
        else if (s.charAt(i) == '-') {
            isPositive = false;
            i++;
        }
        else if (!Character.isDigit(s.charAt(i))) {
            return 0;
        }

        int solution = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int pop = (int) (s.charAt(i) - '0');
            if (isPositive) {
                if (solution > Integer.MAX_VALUE/10 || (solution == Integer.MAX_VALUE/10 && pop > 7)) {
                    return Integer.MAX_VALUE;
                }
            }
            else {
                if (-solution < Integer.MIN_VALUE/10 || (-solution == Integer.MIN_VALUE/10 && pop > 8)) {
                    return Integer.MIN_VALUE;
                }
            }
            solution = solution * 10 + pop;
            i++;
        }
        
        return (isPositive) ? solution : -solution;
    }
}