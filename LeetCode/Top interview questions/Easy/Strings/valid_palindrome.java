/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
 */

class Solution {
    public boolean isPalindrome(String s) {
        
        int start = 0;
        int end = s.length()-1;
        
        while(start < end){
            
            if(isAlphaNumberic(s.charAt(start)) && isAlphaNumberic(s.charAt(end))){
                if(Character.toLowerCase(s.charAt(start++)) != Character.toLowerCase(s.charAt(end--))){
                    return false;
                } 
            } else {  
            
                if(!isAlphaNumberic(s.charAt(start))){
                    start++;
                } 

                if(!isAlphaNumberic(s.charAt(end))){
                    end--;
                } 
            }   
        }
        
        return true;
    
    }
    
    private boolean isAlphaNumberic(char c){
        return Character.isLetter(c) || Character.isDigit(c);
    }
}