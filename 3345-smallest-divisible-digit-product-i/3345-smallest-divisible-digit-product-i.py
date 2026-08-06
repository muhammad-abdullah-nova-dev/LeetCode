class Solution:

    def digitProduct(self, num):

        product = 1

        while num > 0:
            product *= (num % 10)
            num //= 10

        return product

    def smallestNumber(self, n: int, t: int) -> int:

        while True:

            if self.digitProduct(n) % t == 0:
                return n

            n += 1