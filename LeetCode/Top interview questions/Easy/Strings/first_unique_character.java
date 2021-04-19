/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
 */

class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> map = new HashMap<>();
        Set<Character> set = new HashSet<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                set.remove(s.charAt(i));
            }
            else {
                map.put(s.charAt(i), i);
                set.add(s.charAt(i));
            }
        }

        if (set.isEmpty()) {
            return -1;
        }
        
        int solution = map.get(set.iterator().next());
        for (char ch: set) {
            solution = Math.min(solution, map.get(ch));
        }
        
        return solution;
    }
}