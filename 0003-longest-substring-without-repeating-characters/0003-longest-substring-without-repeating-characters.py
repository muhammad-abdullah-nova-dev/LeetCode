class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        left = 0
        ans = 0

        freq = [0] * 256

        for right in range(len(s)):

            freq[ord(s[right])] += 1

            while freq[ord(s[right])] > 1:
                freq[ord(s[left])] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans