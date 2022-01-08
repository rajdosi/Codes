class Solution {
	Map<Integer, Integer> elementToCount;
	Set<Integer> uniqueElements;

	public int getMinRange(int[] nums) {
		if (nums == null) {
			return 0;
		}

		if (nums.length == 1) {
			return 1;
		}

		elementToCount = new HashMap<>();
		uniqueElements = new HashSet<>();
		for (int num : nums) {
			uniqueElements.add(num);
		}

		int j = 0;
		int length = nums.length;
		int minimum = Integer.MAX_VALUE;
		for (int i = 0; i < length && j < length; i++) {
			while (j < length && elementToCount.size() == uniqueElements.size()) {
				int count = elementToCount.getOrDefault(nums[j], 0);
				elementToCount.put(nums[j], count + 1);
				j++;
			}

			if (elementToCount.size() == uniqueElements.size()) {
				minimum = Math.min(minimum, j - i + 1);
			}
			decrementMapValue(nums[i]);
		}

		return minimum;
	}

	private void decrementMapValue(int element) {
		int count = elementToCount.getOrDefault(element, 0);
		if (count - 1 == 0) { 
			elementToCount.remove(element);
		} else {
			elementToCount.put(element, count - 1);
		}
	}
}

/*
array - [ 7 1 6 2 7 2 7 4 1 7 ]
hashset - [ 1 2 4 6 7 ]
hashMap - 
7 -> 3
1 -> 1
2 -> 1
4 -> 1

i = 3;
j = 10;

minimum = 7
*/
