class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Frequency of characters required from t
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int formed = 0;
        int required = need.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            // This character has now satisfied its requirement
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Current window contains all characters of t
            while (formed == required) {

                // Update smallest window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                window[leftChar]--;

                // Window is no longer satisfying this character
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};