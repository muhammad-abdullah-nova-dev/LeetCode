class Solution:
    def firstStableIndex(self, nums, k):
        for i in range(len(nums)):
            
            maximum = max(nums[:i + 1])
            minimum = min(nums[i:])

            if maximum - minimum <= k:
                return i

        return -1