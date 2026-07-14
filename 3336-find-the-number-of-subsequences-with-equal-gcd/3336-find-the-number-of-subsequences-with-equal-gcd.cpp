class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<long long>> dp(mx + 1, vector<long long>(mx + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {
                    if (dp[g1][g2] == 0) continue;

                    int ng1 = gcd(g1, x);
                    int ng2 = gcd(g2, x);

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + dp[g1][g2]) % MOD;

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= mx; g++)
            ans = (ans + dp[g][g]) % MOD;

        return ans;
    }
};