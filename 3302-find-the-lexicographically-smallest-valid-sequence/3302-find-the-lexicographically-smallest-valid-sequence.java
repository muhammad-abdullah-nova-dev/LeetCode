import java.util.*;

class Solution {
    public int[] validSequence(String word1, String word2) {

        int n = word1.length();
        int m = word2.length();

        // nxtIdx[i][c] = first index >= i
        // where character c occurs in word1
        int[][] nxtIdx = new int[n + 1][26];

        Arrays.fill(nxtIdx[n], -1);

        for (int i = n - 1; i >= 0; i--) {
            nxtIdx[i] = nxtIdx[i + 1].clone();

            nxtIdx[i][word1.charAt(i) - 'a'] = i;
        }

        // suff[j] = position where word2[j]
        // can be matched when matching from right
        int[] suff = new int[m];
        Arrays.fill(suff, -1);

        int k = m - 1;

        for (int i = n - 1; i >= 0 && k >= 0; i--) {

            if (word1.charAt(i) == word2.charAt(k)) {
                suff[k] = i;
                k--;
            }
        }

        int[] ans = new int[m];

        int size = 0;

        int i = 0;
        int j = 0;

        boolean used = false;

        while (i < n && j < m) {

            int idx = nxtIdx[i][word2.charAt(j) - 'a'];

            // Mismatch already used
            if (used) {

                if (idx == -1)
                    return new int[0];

                if (j < m - 1 && suff[j + 1] <= idx)
                    return new int[0];

                ans[size++] = idx;

                i = idx + 1;
                j++;
            }

            // Mismatch still available
            else {

                // Exact match
                if (word1.charAt(i) == word2.charAt(j)) {

                    ans[size++] = i;

                    i++;
                    j++;
                }

                // Use mismatch here
                else if (
                    j == m - 1 ||
                    (suff[j + 1] != -1 && i < suff[j + 1])
                ) {

                    used = true;

                    ans[size++] = i;

                    i++;
                    j++;
                }

                // Skip current index
                else {
                    i++;
                }
            }
        }

        if (size == m)
            return ans;

        return new int[0];
    }
}