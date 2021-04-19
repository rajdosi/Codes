/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/
 */

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        
        if (strs.length == 1) {
            return strs[0];
        }
        
        int strLength = Integer.MAX_VALUE;

        for (int i = 0; i < strs.length; i++) {
            strLength = Math.min(strLength, strs[i].length());
        }
        
        int count = 0;
        while (true) {
            if (count == strLength) {
                return strs[0].substring(0, count);
            }
            
            for (int i = 0; i < strs.length - 1; i++) {
                if (strs[i].charAt(count) != strs[i + 1].charAt(count)) {
                    return strs[0].substring(0, count);
                }

            }
            count++;
        }
    }
}