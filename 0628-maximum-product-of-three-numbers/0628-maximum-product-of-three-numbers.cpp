class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX;

        for (int x : nums) {

            // Three largest
            if (x >= mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            }
            else if (x >= mx2) {
                mx3 = mx2;
                mx2 = x;
            }
            else if (x > mx3) {
                mx3 = x;
            }

            // Two smallest
            if (x <= mn1) {
                mn2 = mn1;
                mn1 = x;
            }
            else if (x < mn2) {
                mn2 = x;
            }
        }

        return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
    }
};