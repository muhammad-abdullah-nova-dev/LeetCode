class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char ch : s) {
            count[ch - 'a']++;
        }

        int n = s.size();
        int matched = 0;

        while (matched < n && count[target[matched] - 'a'] > 0) {
            count[target[matched] - 'a']--;
            matched++;
        }

        int start = (matched < n ? matched : n - 1);

        for (int i = start; i >= 0; i--) {
            if (i < matched) {
                count[target[i] - 'a']++;
            }

            int bigger = -1;
            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (count[ch] > 0) {
                    bigger = ch;
                    break;
                }
            }

            if (bigger != -1) {
                count[bigger]--;

                string answer = target.substr(0, i);

                answer += char('a' + bigger);

                for (int ch = 0; ch < 26; ch++) {
                    answer.append(count[ch], char('a' + ch));
                }

                return answer;
            }
        }

        return "";
    }
};