class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // Map each value to its group
        unordered_map<int, int> numToGroup;

        // Store values of each group in sorted order
        unordered_map<int, list<int>> groupToNums;

        int group = 0;

        numToGroup[sortedNums[0]] = group;
        groupToNums[group].push_back(sortedNums[0]);

        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] > limit) {
                group++;
            }

            numToGroup[sortedNums[i]] = group;
            groupToNums[group].push_back(sortedNums[i]);
        }

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int g = numToGroup[nums[i]];

            result[i] = groupToNums[g].front();
            groupToNums[g].pop_front();
        }

        return result;
    }
};