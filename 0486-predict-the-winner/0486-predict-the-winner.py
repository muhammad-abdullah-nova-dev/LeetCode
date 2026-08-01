class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:

        memo = {}

        def solve(left, right):

            if left == right:
                return nums[left]

            if (left, right) in memo:
                return memo[(left, right)]

            take_left = nums[left] - solve(left + 1, right)
            take_right = nums[right] - solve(left, right - 1)

            memo[(left, right)] = max(take_left, take_right)

            return memo[(left, right)]

        return solve(0, len(nums) - 1) >= 0