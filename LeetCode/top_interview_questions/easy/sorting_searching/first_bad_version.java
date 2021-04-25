/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/
 */
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1, high = n;
        
        while (low < high) {
            int mid = low + (high - low)/2;
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
}