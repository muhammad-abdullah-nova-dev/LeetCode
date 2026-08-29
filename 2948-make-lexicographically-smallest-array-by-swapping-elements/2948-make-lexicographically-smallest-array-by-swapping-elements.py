class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)

        sorted_nums = sorted(nums)

        # value -> group
        num_to_group = {}

        # group -> list of values
        group_to_nums = {}

        group = 0

        num_to_group[sorted_nums[0]] = group
        group_to_nums[group] = [sorted_nums[0]]

        for i in range(1, n):
            if sorted_nums[i] - sorted_nums[i - 1] > limit:
                group += 1

            num_to_group[sorted_nums[i]] = group

            if group not in group_to_nums:
                group_to_nums[group] = []

            group_to_nums[group].append(sorted_nums[i])

        # Pointer for each group
        pointers = {g: 0 for g in group_to_nums}

        result = [0] * n

        for i in range(n):
            g = num_to_group[nums[i]]

            result[i] = group_to_nums[g][pointers[g]]
            pointers[g] += 1

        return result