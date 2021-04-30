/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/
 */

class Solution1 {
    public List<String> fizzBuzz(int n) {
        List<String> solution = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String str = "";
            
            if (i % 3 == 0) {
                str += "Fizz";
            }
            
            if (i % 5 == 0) {
                str += "Buzz";
            }
            
            if (str == "") {
                str += String.valueOf(i);
            }

            solution.add(str);
        }
        
        return solution;
    }
}

class Solution2 {
    public List<String> fizzBuzz(int n) {
        List<String> solution = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                solution.add("FizzBuzz");
            }
            else if (i % 3 == 0) {
                solution.add("Fizz");
            }
            else if (i % 5 == 0) {
                solution.add("Buzz");
            }
            else {
                solution.add(String.valueOf(i));
            }
        }
        
        return solution;
    }
}