/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/
 */ 
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next !=null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        if (fast != null) {
            slow = slow.next;
        }
        
        fast = reverse(slow);
        
        slow = head;
        while (fast != null) {
            if (fast.val == slow.val) {
                fast = fast.next;
                slow = slow.next;
            }
            else {
                return false;
            }
        }
        
        return true;
    }
    
    private ListNode reverse(ListNode node) {
        ListNode curr = node;
        ListNode prev = null;
        
        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
}

class Solution2 {
    private ListNode left, start;
    
    public boolean isPalindrome(ListNode head) {
        start = head;
        return isPalindromeRecur(head);
    }
    
    private boolean isPalindromeRecur(ListNode right) {
        left = start;
        
        if (right == null) {
            return true;
        }
        
        boolean isPalindrome = isPalindromeRecur(right.next);
        if (!isPalindrome) {
            return false;
        }
        
        if (left.val == right.val) {
            left = left.next;    
            return true;
        }

        return false;
    }
}