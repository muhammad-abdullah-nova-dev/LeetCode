class Solution {
    public int minimumDeletions(int[] nums) {

        int n = nums.length;

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

        int option1 = Math.max(distanceFromStartMin, distanceFromStartMax) + 1;
        int option2 = Math.max(distanceFromEndMin, distanceFromEndMax) + 1;

        int option3 = distanceFromStartMin + 1
                    + distanceFromEndMax + 1;

        int option4 = distanceFromStartMax + 1
                    + distanceFromEndMin + 1;

        return Math.min(Math.min(option1, option2),
                        Math.min(option3, option4));
    }
}