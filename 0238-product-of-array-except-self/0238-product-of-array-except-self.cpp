class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer(n, 1);

        int product = 1;

        // Prefix products
        for (int i = 0; i < n; i++) {
            answer[i] = product;
            product *= nums[i];
        }

        int suffix = 1;

        // Suffix products
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};