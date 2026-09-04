class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (*max_element(nums.begin(), nums.begin() + i + 1) -
                *min_element(nums.begin() + i, nums.end()) <= k) {
                return i;
            }
        }

        return -1;
    }
};