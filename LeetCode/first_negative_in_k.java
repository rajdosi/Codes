public class Solution {
	public int[] getFirstNegative(int[] input, int k) {
		if (k < input.length) {
			throw new RuntimeException("invalid input");
		}

		List<Intger> negativeIndexes = new ArrayList<>();

		int i = 0, j = 0; 
		while (j < k) {
			if (input[j] < 0) {
				negativeIndexes.add(j);
			}

			j++;
		}

		int current = 0;
		int[] answer = new int[input.length - k];
		for (; j < n; i++, j++) {
			if (negativeIndexes.size() == 0) {
				answer.add(0);
			}
			else {
				int firstNegativeIndex = negativeIndexes.get(current);
				if (i <= firstNegativeIndex && firstNegativeIndex < j) {
					answer.add(input[firstNegativeIndex]);
				} else {
					answer.add(0);
				}

				if (i == firstNegativeIndex) {
					current++;
				}

				if (input[j] < 0) {
					negativeIndexes.add(j);
				}
			}
		}

		return answer;
	}
}