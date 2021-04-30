/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/878/
 */
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> numberToValueMap = new HashMap<>();
        numberToValueMap.put('I', 1);
        numberToValueMap.put('V', 5);
        numberToValueMap.put('X', 10);
        numberToValueMap.put('L', 50);
        numberToValueMap.put('C', 100);
        numberToValueMap.put('D', 500);
        numberToValueMap.put('M', 1000);
        
        if (s.length() == 1) {
            return numberToValueMap.get(s.charAt(0));
        }
        
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {

            if (i + 1 < s.length()) {
                
                if (numberToValueMap.get(s.charAt(i)) < numberToValueMap.get(s.charAt(i + 1))) {
                    answer += numberToValueMap.get(s.charAt(i + 1)) - numberToValueMap.get(s.charAt(i));
                    i++;
                }   
                else {            
                    answer += numberToValueMap.get(s.charAt(i));
                }
            }
            else {
                answer += numberToValueMap.get(s.charAt(i));
            }
        }
        
        return answer;
    }
}