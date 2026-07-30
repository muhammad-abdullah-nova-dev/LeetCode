class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans=0;
        vector<int> freq(256, 0);
        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;

            while (freq[s[r]] > 1)
            {
                // Remove left character
                freq[s[l]]--;
                l++;
            }

                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};