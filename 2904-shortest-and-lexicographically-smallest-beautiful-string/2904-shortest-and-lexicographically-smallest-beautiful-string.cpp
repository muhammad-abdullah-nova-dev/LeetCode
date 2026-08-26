class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string answer = "";
        int left = 0;
        int ones = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            while (ones == k && s[left] == '0') {
                left++;
            }

            if (ones == k) {
                int length = right - left + 1;

                string candidate = s.substr(left, length);

                if (answer.empty() ||
                    candidate.size() < answer.size() ||
                    (candidate.size() == answer.size() && candidate < answer)) {
                    answer = candidate;
                }
            }
        }

        return answer;
    }
};