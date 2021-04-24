/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/
 */

public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }
        
        ListNode fast = head.next;
        
        while (head != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            
            head = head.next;
            fast = fast.next.next;
        }
        
        return true;
    }
}

public class Solution2 {
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }
        
        ListNode point = new ListNode(-1);
        
        while (head != null) {
            if (head.next == point) {
                return true;
            }
            
            ListNode temp = head;
            head = head.next;
            temp.next = point;
        }
        
        return false;
    }
}