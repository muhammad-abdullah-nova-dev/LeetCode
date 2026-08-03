class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:

        n = len(stoneValue)

        dp = [float('-inf')] * (n + 1)

        dp[n] = 0

        for i in range(n - 1, -1, -1):

            total = 0

            for k in range(3):

                if i + k >= n:
                    break

                total += stoneValue[i + k]

                dp[i] = max(dp[i], total - dp[i + k + 1])

        if dp[0] > 0:
            return "Alice"

        if dp[0] < 0:
            return "Bob"

        return "Tie"