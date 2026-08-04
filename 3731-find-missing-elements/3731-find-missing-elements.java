import java.util.*;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {

        int mn = Integer.MAX_VALUE;
        int mx = Integer.MIN_VALUE;

        HashSet<Integer> set = new HashSet<>();

        for (int num : nums) {
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
            set.add(num);
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = mn; i <= mx; i++) {
            if (!set.contains(i)) {
                ans.add(i);
            }
        }

        return ans;
    }
}