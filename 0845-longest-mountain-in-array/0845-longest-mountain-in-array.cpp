class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int up = 0, down = 0, ans = 0;

        for (int i = 1; i < n; i++) {

            // Reset if a new mountain starts
            if ((down > 0 && arr[i] > arr[i - 1]) ||
                arr[i] == arr[i - 1]) {
                up = down = 0;
            }

            if (arr[i] > arr[i - 1])
                up++;

            else if (arr[i] < arr[i - 1])
                down++;

            if (up > 0 && down > 0)
                ans = max(ans, up + down + 1);
        }

        return ans;
    }
};