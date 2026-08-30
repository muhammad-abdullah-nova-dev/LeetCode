class Solution:
    def minimumDeletions(self, nums):

        n = len(nums)

        minIndex = nums.index(min(nums))
        maxIndex = nums.index(max(nums))

        distanceFromStartMin = minIndex
        distanceFromStartMax = maxIndex

        distanceFromEndMin = n - minIndex - 1
        distanceFromEndMax = n - maxIndex - 1

        option1 = max(distanceFromStartMin, distanceFromStartMax) + 1

        option2 = max(distanceFromEndMin, distanceFromEndMax) + 1

        option3 = distanceFromStartMin + 1 + distanceFromEndMax + 1

        option4 = distanceFromStartMax + 1 + distanceFromEndMin + 1

        return min(option1, option2, option3, option4)