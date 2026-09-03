func uniformArray(nums1 []int) bool {
	const inf = int(1e18)

	minOdd := inf
	minEven := inf

	for _, x := range nums1 {
		if x%2 == 0 {
			if x < minEven {
				minEven = x
			}
		} else {
			if x < minOdd {
				minOdd = x
			}
		}
	}

	if minOdd == inf {
		return true
	}

	return minOdd < minEven
}