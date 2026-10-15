public class Solution {
    public int SumCounts(IList<int> nums) {
        int n = nums.Count;
        int res = 0;
        for (int i = 0; i < n; i++) {
            HashSet<int> s = new HashSet<int>();
            for (int j = i; j < n; j++) {
                s.Add(nums[j]);
                res += s.Count * s.Count;
            }
        }
        return res;
    }
}