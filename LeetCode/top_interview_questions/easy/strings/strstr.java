/*
 * https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/
 */

class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) {
            return 0;
        }
        
        if (haystack.length() == 0) {
            return -1;
        }
        
        int[] lps = new int[needle.length()];
        int j = 0, i = 0;

        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
                if (j == needle.length()) {
                    return i - (needle.length() - 1);
                }
                i++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        
        return -1;        
    }
    
    private int[] createLPS(String needle) {
        int i = 1, j = 0;
        int[] lps = new int[needle.length()];
        lps[0] = 0;

        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(j)) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return lps;            
    }
}