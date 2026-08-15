func longestSubsequence(nums []int) int {
	xorValue := 0
	hasNonZero := false

	for _, x := range nums {
		xorValue ^= x

		if x != 0 {
			hasNonZero = true
		}
	}

	if xorValue != 0 {
		return len(nums)
	}

	if hasNonZero {
		return len(nums) - 1
	}

	return 0
}