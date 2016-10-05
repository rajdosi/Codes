package projecteulerjava;

import java.util.HashMap;
import java.util.Map;

public class q062 {

	private static String calculatePermutationValue(long cube) {

		long cubeCopy = cube;
		int[] digitArray = new int[10];
		while (cubeCopy > 0) {
			digitArray[(int) (cubeCopy % 10L)]++;
			cubeCopy /= 10;
		}

		String largestPermutation = new String();
		for (Integer i = 9; i >= 0; i--) {
			for (int j = 0; j < digitArray[i]; j++) {
				largestPermutation = largestPermutation + i.toString();
			}
		}
		return largestPermutation;
	}

	public static void main(String[] args) {
		class Cube {
			public Long value;
			public Integer perms;

			public Cube(Long val, Integer p) {
				this.value = val;
				this.perms = p;
			}
		}
		Map<String, Cube> cubePermMap = new HashMap<>();

		long counter = 11L;
		Cube result;

		while (true) {
			counter++;
			String largestPerm = calculatePermutationValue((counter * counter * counter));
			if (!cubePermMap.containsKey(largestPerm)) {
				cubePermMap.put(largestPerm, new Cube(counter, 0));
			}
			if (++cubePermMap.get(largestPerm).perms == 5) {
				result = cubePermMap.get(largestPerm);
				break;
			}
		}

		System.out.println("Number : "
				+ result.value
				+ "\t Cube : "
				+ (result.value * result.value * result.value)
				+ "\t PermutationValue : "
				+ calculatePermutationValue(result.value * result.value
						* result.value));

	}
}
