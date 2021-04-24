/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/
 */

class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}