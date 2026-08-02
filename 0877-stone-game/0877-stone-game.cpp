class Solution {
public:
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& piles) {
        if (l == r)
            return piles[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        int left = piles[l] - solve(l + 1, r, piles);
        int right = piles[r] - solve(l, r - 1, piles);

        return dp[l][r] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, piles) > 0;
    }
};