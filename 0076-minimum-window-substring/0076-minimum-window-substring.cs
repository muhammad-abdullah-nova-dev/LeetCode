public class Solution {
    public string MinWindow(string s, string t) {
        if (t.Length > s.Length)
            return "";

        Dictionary<char, int> need = new Dictionary<char, int>();
        Dictionary<char, int> window = new Dictionary<char, int>();

        foreach (char c in t) {
            if (need.ContainsKey(c))
                need[c]++;
            else
                need[c] = 1;
        }

        int left = 0;
        int formed = 0;
        int required = need.Count;

        int minLen = int.MaxValue;
        int start = 0;

        for (int right = 0; right < s.Length; right++) {

            char c = s[right];

            if (window.ContainsKey(c))
                window[c]++;
            else
                window[c] = 1;

            if (need.ContainsKey(c) &&
                window[c] == need[c]) {
                formed++;
            }

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.ContainsKey(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        return minLen == int.MaxValue
            ? ""
            : s.Substring(start, minLen);
    }
}