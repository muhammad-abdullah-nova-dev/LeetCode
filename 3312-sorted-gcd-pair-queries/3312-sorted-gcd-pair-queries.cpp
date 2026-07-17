class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[g] = numbers divisible by g
        vector<long long> cnt(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                cnt[g] += freq[j];
        }

        // exact[g] = pairs with gcd exactly g
        vector<long long> exact(mx + 1, 0);
        for (int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int j = g + g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        // prefix[g] = pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;
        for (long long k : queries) {
            // queries are 0-indexed
            int g = lower_bound(prefix.begin() + 1, prefix.end(), k + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};