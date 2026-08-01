class Solution {

    Integer[][] dp;

    private int solve(int left, int right, int[] nums) {

        if (left == right)
            return nums[left];

        if (dp[left][right] != null)
            return dp[left][right];

        int takeLeft = nums[left] - solve(left + 1, right, nums);
        int takeRight = nums[right] - solve(left, right - 1, nums);

        return dp[left][right] = Math.max(takeLeft, takeRight);
    }

    public boolean predictTheWinner(int[] nums) {

        int n = nums.length;
        dp = new Integer[n][n];

        return solve(0, n - 1, nums) >= 0;
    }
}