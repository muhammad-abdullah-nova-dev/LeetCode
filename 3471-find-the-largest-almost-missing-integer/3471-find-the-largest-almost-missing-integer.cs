public class Solution {
    public int LargestInteger(int[] nums, int k) {
        int n = nums.Length;
        int[] count = new int[51];

        for (int i = 0; i <= n - k; i++) {
            HashSet<int> seen = new HashSet<int>();

            for (int j = i; j < i + k; j++) {
                seen.Add(nums[j]);
            }

            foreach (int x in seen) {
                count[x]++;
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
}