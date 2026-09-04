public class Solution {
    public int FirstStableIndex(int[] nums, int k) {
        for (int i = 0; i < nums.Length; i++) {
            int max = int.MinValue;
            int min = int.MaxValue;

            for (int j = 0; j <= i; j++) {
                max = Math.Max(max, nums[j]);
            }

            for (int j = i; j < nums.Length; j++) {
                min = Math.Min(min, nums[j]);
            }

            if (max - min <= k) {
                return i;
            }
        }

        return -1;
    }
}