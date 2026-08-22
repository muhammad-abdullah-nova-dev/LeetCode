class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum = 0
        product = 1
        newVar = n

        while newVar != 0:
            temp = newVar % 10
            sum += temp
            product *= temp
            newVar //= 10

        newSum = sum + product

        return n % newSum == 0