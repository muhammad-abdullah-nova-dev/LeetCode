class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // nxtIdx[i][c] = first index >= i
        // where character c occurs in word1
        vector<vector<int>> nxtIdx(n + 1, vector<int>(26, -1));

        for (int i = n - 1; i >= 0; i--) {
            nxtIdx[i] = nxtIdx[i + 1];
            nxtIdx[i][word1[i] - 'a'] = i;
        }

        // suff[j] = position where word2[j] can be matched
        // when matching word2 from right to left.
        vector<int> suff(m, -1);

        int k = m - 1;

        for (int i = n - 1; i >= 0 && k >= 0; i--) {
            if (word1[i] == word2[k]) {
                suff[k] = i;
                k--;
            }
        }

        vector<int> ans;

        int i = 0;
        int j = 0;

        // Have we already used our one allowed mismatch?
        bool used = false;

        while (i < n && j < m) {

            // Earliest occurrence of word2[j]
            // from position i onward.
            int idx = nxtIdx[i][word2[j] - 'a'];

            // ----------------------------------------
            // Mismatch has already been used
            // ----------------------------------------
            if (used) {

                if (idx == -1)
                    return {};

                // We need enough room for the rest.
                if (j < m - 1 && suff[j + 1] <= idx)
                    return {};

                ans.push_back(idx);

                i = idx + 1;
                j++;
            }

            // ----------------------------------------
            // Mismatch is still available
            // ----------------------------------------
            else {

                // Exact match at current position.
                if (word1[i] == word2[j]) {

                    ans.push_back(i);
                    i++;
                    j++;
                }

                // Use our one mismatch here.
                else if (
                    j == m - 1 ||
                    (suff[j + 1] != -1 && i < suff[j + 1])
                ) {

                    used = true;

                    ans.push_back(i);

                    i++;
                    j++;
                }

                // Current index cannot be used.
                else {
                    i++;
                }
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};