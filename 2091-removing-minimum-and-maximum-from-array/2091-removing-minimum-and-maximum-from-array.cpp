class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int n = nums.size();

        int distanceFromStartMin = minIndex;
        int distanceFromStartMax = maxIndex;

        int distanceFromEndMin = n - minIndex - 1;
        int distanceFromEndMax = n - maxIndex - 1;

        int option1 = max(distanceFromStartMin, distanceFromStartMax) + 1;

        int option2 = max(distanceFromEndMin, distanceFromEndMax) + 1;

        int option3 = distanceFromStartMin + 1 + distanceFromEndMax + 1;

        int option4 = distanceFromStartMax + 1 + distanceFromEndMin + 1;

        return min({option1, option2, option3, option4});
    }
};