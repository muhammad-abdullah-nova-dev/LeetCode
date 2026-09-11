class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        s, n = set(), len(digits)
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    if i != j and i != k and j != k:
                        s.add(100 * digits[i] + 10 * digits[j] + digits[k])
        return sum(v > 99 and v % 2 == 0 for v in s)