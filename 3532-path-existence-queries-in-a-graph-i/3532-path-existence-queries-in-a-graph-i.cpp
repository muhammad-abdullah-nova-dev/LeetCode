class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);

        int id = 0;
        component[0] = id;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            component[i] = id;
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            ans.push_back(component[q[0]] == component[q[1]]);
        }

        return ans;
    }
};