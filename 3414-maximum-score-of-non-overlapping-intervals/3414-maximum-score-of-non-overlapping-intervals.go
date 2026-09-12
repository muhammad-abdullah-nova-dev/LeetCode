func maximumWeight(intervals [][]int) []int {
	type State struct {
		score  int64
		ids    []int
		valid  bool
	}

	n := len(intervals)
	const K = 4

	a := make([][4]int64, n)

	for i := 0; i < n; i++ {
		a[i] = [4]int64{
			int64(intervals[i][0]),
			int64(intervals[i][1]),
			int64(intervals[i][2]),
			int64(i),
		}
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i][1] < a[j][1]
	})

	ends := make([]int64, n)
	for i := 0; i < n; i++ {
		ends[i] = a[i][1]
	}

	dp := make([][]State, K+1)
	for k := 0; k <= K; k++ {
		dp[k] = make([]State, n+1)
	}

	for i := 0; i <= n; i++ {
		dp[0][i] = State{
			score: 0,
			ids:   []int{},
			valid: true,
		}
	}

	better := func(a State, b State) bool {
		if !a.valid {
			return false
		}
		if !b.valid {
			return true
		}

		if a.score != b.score {
			return a.score > b.score
		}

		for i := 0; i < len(a.ids) && i < len(b.ids); i++ {
			if a.ids[i] != b.ids[i] {
				return a.ids[i] < b.ids[i]
			}
		}

		return len(a.ids) < len(b.ids)
	}

	lowerBound := func(length int, target int64) int {
		lo := 0
		hi := length

		for lo < hi {
			mid := lo + (hi-lo)/2

			if ends[mid] >= target {
				hi = mid
			} else {
				lo = mid + 1
			}
		}

		return lo
	}

	for i := 1; i <= n; i++ {
		left := a[i-1][0]
		weight := a[i-1][2]
		originalIndex := int(a[i-1][3])

		p := lowerBound(i-1, left)

		for k := 1; k <= K; k++ {
			dp[k][i] = dp[k][i-1]

			prev := dp[k-1][p]

			if prev.valid {
				ids := append([]int{}, prev.ids...)

				ids = append(ids, originalIndex)

				sort.Ints(ids)

				take := State{
					score: prev.score + weight,
					ids:   ids,
					valid: true,
				}

				if better(take, dp[k][i]) {
					dp[k][i] = take
				}
			}
		}
	}

	var answer State

	for k := 1; k <= K; k++ {
		if better(dp[k][n], answer) {
			answer = dp[k][n]
		}
	}

	return answer.ids
}