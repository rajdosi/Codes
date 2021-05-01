/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/721/
 */
class Solution {
    private static Map<Character, Character> openToCloseMap = new HashMap<>();
    
    static {
        openToCloseMap.put('{', '}');
        openToCloseMap.put('(', ')');
        openToCloseMap.put('[', ']');
    }
    
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (openToCloseMap.containsKey(s.charAt(i))) {
                stack.push(s.charAt(i));
            }
            else {
                if (stack.isEmpty() || s.charAt(i) != openToCloseMap.get(stack.peek())) {
                    return false;
                }
                
                stack.pop();
            }
        }
        
        return stack.isEmpty();
    }
}