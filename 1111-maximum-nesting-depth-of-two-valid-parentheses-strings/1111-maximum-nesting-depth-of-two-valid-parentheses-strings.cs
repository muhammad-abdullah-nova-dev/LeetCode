public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        int n = seq.Length;
        int[] ans = new int[n];
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                d++;
                ans[i] = d % 2;
            }
            if (seq[i] == ')') {
                ans[i] = d % 2;
                d--;
            }
        }
        return ans;
    }
}