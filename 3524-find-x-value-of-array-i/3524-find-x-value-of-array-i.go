func resultArray(nums []int, k int) []int64 {
    n := len(nums)
    result := make([]int64, k)
    dp := make([]int64, k)  // Initial state: no elements have been processed, so no non-empty subarray exists.

    for i := 0; i < n; i++ {
        ndp := make([]int64, k)  // Current-layer state (rolling array).
        ndp[nums[i] % k]++
        for r := 0; r < k; r++ {
            ndp[(int64(r) * int64(nums[i])) % int64(k)] += dp[r]
        }

        dp = ndp  // Update the state.

        // Accumulate the answer.
        for r := 0; r < k; r++ {
            result[r] += dp[r]
        }
    }

    return result
}