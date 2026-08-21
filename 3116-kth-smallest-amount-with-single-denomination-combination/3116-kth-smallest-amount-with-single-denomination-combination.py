class Solution:

    def gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a

    def lcm(self, a, b):
        return a // self.gcd(a, b) * b

    def count(self, x, coins):
        ans = 0
        n = len(coins)

        for mask in range(1, 1 << n):
            L = 1
            bits = 0
            valid = True

            for i in range(n):
                if mask & (1 << i):
                    bits += 1

                    L = self.lcm(L, coins[i])

                    if L > x:
                        valid = False
                        break

            if not valid:
                continue

            ways = x // L

            if bits % 2 == 1:
                ans += ways
            else:
                ans -= ways

        return ans

    def findKthSmallest(self, coins, k):
        low = 1
        high = min(coins) * k

        while low < high:
            mid = low + (high - low) // 2

            if self.count(mid, coins) >= k:
                high = mid
            else:
                low = mid + 1

        return low