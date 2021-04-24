/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        ListNode dummy = new ListNode();
        ListNode node = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                node.next = new ListNode(l1.val);
                l1 = l1.next;
            }
            else {
                node.next = new ListNode(l2.val);
                l2 = l2.next;
            }
            
            node = node.next;
        }
        
        if (l1 != null) {
            node.next = l1;
        }
        else if (l2 != null) {
            node.next = l2;
        }
        
        return dummy.next;
    }
}