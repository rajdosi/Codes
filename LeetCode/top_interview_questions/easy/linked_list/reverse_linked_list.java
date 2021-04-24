/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/
 */

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current = head;
        ListNode previous = null;

        while (current != null) {
            ListNode temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }
        
        return previous;
    }
}