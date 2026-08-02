class Solution:
    def stoneGame(self, piles: List[int]) -> bool:

        memo = {}

        def solve(l, r):
            if l == r:
                return piles[l]

            if (l, r) in memo:
                return memo[(l, r)]

            left = piles[l] - solve(l + 1, r)
            right = piles[r] - solve(l, r - 1)

            memo[(l, r)] = max(left, right)
            return memo[(l, r)]

        return solve(0, len(piles) - 1) > 0