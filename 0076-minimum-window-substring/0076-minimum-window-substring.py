class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        need = {}
        window = {}

        for c in t:
            need[c] = need.get(c, 0) + 1

        left = 0
        formed = 0
        required = len(need)

        min_len = float("inf")
        start = 0

        for right in range(len(s)):

            c = s[right]
            window[c] = window.get(c, 0) + 1

            if c in need and window[c] == need[c]:
                formed += 1

            while formed == required:

                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    start = left

                left_char = s[left]
                window[left_char] -= 1

                if (left_char in need and
                        window[left_char] < need[left_char]):
                    formed -= 1

                left += 1

        if min_len == float("inf"):
            return ""

        return s[start:start + min_len]