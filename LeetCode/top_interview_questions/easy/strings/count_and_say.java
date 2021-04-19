/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/
 */

class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        String current = "11";

        while(n != 2) {
            StringBuilder newCurrent = new StringBuilder();
            for (int i = 0; i < current.length(); i++) {
                int count = 1;
                while (i < current.length() - 1 && (current.charAt(i) == current.charAt(i + 1))) {
                    i++; count++;
                }
                newCurrent = newCurrent.append(count);
                newCurrent = newCurrent.append(current.charAt(i));
            }

            current = newCurrent.toString();
            n--;
        }

        return current;
    }
}