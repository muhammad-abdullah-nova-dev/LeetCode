func stoneGameIX(stones []int) bool {
	cnt := [3]int{}

	for _, stone := range stones {
		cnt[stone%3]++
	}

	if cnt[0]%2 == 0 {
		return cnt[1] > 0 && cnt[2] > 0
	}

	diff := cnt[1] - cnt[2]

	if diff < 0 {
		diff = -diff
	}

	return diff > 2
}