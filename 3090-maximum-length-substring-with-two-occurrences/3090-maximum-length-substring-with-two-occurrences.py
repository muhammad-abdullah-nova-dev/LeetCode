class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        freq = [0] * 26

        left = 0

        ans = 0

        for right in range(len(s)):
            index = ord(s[right]) - ord('a')
            freq[index] += 1

            while freq[index] > 2:
                freq[ord(s[left]) - ord('a')] -= 1

                left += 1

            ans = max(ans, right - left + 1)

        return ans