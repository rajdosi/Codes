/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/565/
 */

public class Solution1 {
    public int hammingWeight(int n) {
        int answer = 0;
        while (n != 0) {
            answer++;
            n &= n - 1;
        }
        
        return answer;
    }
}

public class Solution2 {
	public int hammingWeight(int n) {
		int answer = 0;
		int mask = 1;
		for (int i=0; i < 32; i++) {
			if ((n & mask) != 0) {
				answer++;
			}
			mask <<= 1;
		}

		return answer;
	}
}
