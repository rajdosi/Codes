/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
 */

class LogSolution {
    public boolean isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }

        return (Math.log10(n)/Math.log10(3)) % 1 == 0;
    }
}

class BaseSolution {
    public boolean isPowerOfThree(int n) {
        String base3 = Integer.toString(n, 3);
        return base3.matches("^10*$");
    }
}