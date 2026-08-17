class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> need;

        for (string word : words) {
            need[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset;
                 right + wordLen <= s.size();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word is not present in words
                if (need.find(word) == need.end()) {

                    window.clear();
                    count = 0;
                    left = right + wordLen;

                    continue;
                }

                // Add word to window
                window[word]++;
                count++;

                // Too many copies of this word
                while (window[word] > need[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // We have exactly all required words
                if (count == wordCount) {

                    ans.push_back(left);

                    // Remove first word so we can
                    // continue looking for overlapping answers
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};