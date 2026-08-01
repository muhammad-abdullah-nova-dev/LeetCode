class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int>& nums) {
        if (left == right)
            return nums[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = nums[left] - solve(left + 1, right, nums);
        int takeRight = nums[right] - solve(left, right - 1, nums);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, nums) >= 0;
    }
};