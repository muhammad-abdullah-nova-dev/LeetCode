const firstStableIndex = (nums, k) => {
    let maxSoFar = -1;
    let cand = 0, max = 0;

    for (let i = 0; i < nums.length; i++) {
        maxSoFar = Math.max(maxSoFar, nums[i]);

        if (cand === i)
            max = maxSoFar;

        if (nums[i] < max - k)
            cand = i + 1;
    }

    return cand < nums.length ? cand : -1;
};