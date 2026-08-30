public class Solution {
    public int MinimumDeletions(int[] nums) {

        int n = nums.Length;

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int distanceFromStartMin = minIndex;
        int distanceFromStartMax = maxIndex;

        int distanceFromEndMin = n - minIndex - 1;
        int distanceFromEndMax = n - maxIndex - 1;

        int option1 =
            Math.Max(distanceFromStartMin, distanceFromStartMax) + 1;

        int option2 =
            Math.Max(distanceFromEndMin, distanceFromEndMax) + 1;

        int option3 =
            distanceFromStartMin + 1 +
            distanceFromEndMax + 1;

        int option4 =
            distanceFromStartMax + 1 +
            distanceFromEndMin + 1;

        return Math.Min(
            Math.Min(option1, option2),
            Math.Min(option3, option4)
        );
    }
}