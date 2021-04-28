/*
 * https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/670/
 */

class Solution {
    private int[] original;
    private int[] shuffled;

    public Solution(int[] nums) {
      original = Arrays.copyOf(nums,nums.length);  
      shuffled = Arrays.copyOf(nums,nums.length);  
    }

    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        
        int max = shuffled.length-1;
        int min = 0;
        int range = max - min + 1;
        
        int r = (int)(Math.random()*range+min);
        for(int i = 0; i<=max; i++){
            if(r != i){
                swap(shuffled,r,i);
                break;
            }
        }
         
        return shuffled;
    }

    public void swap(int[] nums, int i , int j){  
        int temp = nums[i];
        nums[i]  = nums[j];
        nums[j]  = temp;
    }
}

class Solution2 {
    private int[] original;
    private int[] array;
    private Random random = new Random();
    
    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        array = original;
        original = original.clone();
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for (int i = 0; i < array.length - 1; i++) {
            int j = getRandom(i, array.length);
            swap(i, j);
        }
            
        return array;
    }
    
    private void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    private int getRandom(int min, int max) {
        return random.nextInt(max - min) + max;
    }
}