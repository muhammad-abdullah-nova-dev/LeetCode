var minimumDeletions = function(nums) {

    let n = nums.length;

    let minIndex = 0;
    let maxIndex = 0;

    for (let i = 0; i < n; i++) {
        if (nums[i] < nums[minIndex])
            minIndex = i;

        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }

    let distanceFromStartMin = minIndex;
    let distanceFromStartMax = maxIndex;

    let distanceFromEndMin = n - minIndex - 1;
    let distanceFromEndMax = n - maxIndex - 1;

    let option1 =
        Math.max(distanceFromStartMin, distanceFromStartMax) + 1;

    let option2 =
        Math.max(distanceFromEndMin, distanceFromEndMax) + 1;

    let option3 =
        distanceFromStartMin + 1 +
        distanceFromEndMax + 1;

    let option4 =
        distanceFromStartMax + 1 +
        distanceFromEndMin + 1;

    return Math.min(option1, option2, option3, option4);
};