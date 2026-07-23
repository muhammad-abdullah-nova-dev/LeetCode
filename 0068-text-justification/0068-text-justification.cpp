class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find maximum words that fit in current line
            while (j < n && letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or only one word
            if (j == n || gaps == 0) {
                line += words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " ";
                    line += words[k];
                }

                while (line.size() < maxWidth)
                    line += " ";
            }
            else {
                int totalSpaces = maxWidth - letters;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    line.append(evenSpaces, ' ');
                    if (extraSpaces > 0) {
                        line += " ";
                        extraSpaces--;
                    }
                }

                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};