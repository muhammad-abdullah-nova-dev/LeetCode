class Solution {

    Integer[][] dp;

    private int solve(int l, int r, int[] piles) {

        if (l == r)
            return piles[l];

        if (dp[l][r] != null)
            return dp[l][r];

        int left = piles[l] - solve(l + 1, r, piles);
        int right = piles[r] - solve(l, r - 1, piles);

        return dp[l][r] = Math.max(left, right);
    }

    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        dp = new Integer[n][n];
        return solve(0, n - 1, piles) > 0;
    }
}