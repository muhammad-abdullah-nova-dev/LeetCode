var resultArray = function (nums, k) {
    const n = nums.length;
    const result = new Array(k).fill(0);
    let dp = new Array(k).fill(0); // Initial state: no elements have been processed, so no non-empty subarray exists.

    for (let i = 0; i < n; i++) {
        const ndp = new Array(k).fill(0); // Current-layer state (rolling array).

        ndp[nums[i] % k]++;

        for (let r = 0; r < k; r++) {
            ndp[(r * nums[i]) % k] += dp[r];
        }

        dp = ndp; // Update the state.

        // Accumulate the answer.
        for (let r = 0; r < k; r++) {
            result[r] += dp[r];
        }
    }

    return result;
};