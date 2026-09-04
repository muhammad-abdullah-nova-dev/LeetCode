class Solution {
    public int firstStableIndex(int[] nums, int k) {
        for (int i = 0; i < nums.length; i++) {
            
            int max = nums[0];
            for (int j = 0; j <= i; j++) {
                max = Math.max(max, nums[j]);
            }

            int min = nums[i];
            for (int j = i; j < nums.length; j++) {
                min = Math.min(min, nums[j]);
            }

            if (max - min <= k) {
                return i;
            }
        }

        return -1;
    }
}