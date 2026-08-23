class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        half = n // 2
        sum1 = sum2 = cnt1 = cnt2 = 0

        for c in num[:half]:
            if c == '?':
                cnt1 += 1
            else:
                sum1 += int(c)

        for c in num[half:]:
            if c == '?':
                cnt2 += 1
            else:
                sum2 += int(c)

        totalQ = cnt1 + cnt2
        if totalQ % 2 == 1:
            return True

        return 2 * (sum1 - sum2) != 9 * (cnt2 - cnt1)