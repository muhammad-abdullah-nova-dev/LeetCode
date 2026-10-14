public class Solution {
    public long MaxAlternatingSum(int[] nums) {
        int n = nums.Length;
        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }
        Array.Sort(nums);

        long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans -= nums[i];
        }
        for (int i = n / 2; i < n; i++) {
            ans += nums[i];
        }
        return ans;
    }
}