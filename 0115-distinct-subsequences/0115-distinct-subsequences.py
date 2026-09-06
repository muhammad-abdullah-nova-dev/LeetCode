class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(t)

        dp = [0] * (m + 1)
        dp[0] = 1

        for c in s:
            for j in range(m, 0, -1):
                if c == t[j - 1]:
                    dp[j] += dp[j - 1]

        return dp[m]