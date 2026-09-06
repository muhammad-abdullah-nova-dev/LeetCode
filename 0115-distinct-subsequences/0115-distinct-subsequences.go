func numDistinct(s string, t string) int {
	m := len(t)

	dp := make([]uint64, m+1)
	dp[0] = 1

	for i := 0; i < len(s); i++ {
		c := s[i]

		for j := m; j >= 1; j-- {
			if c == t[j-1] {
				dp[j] += dp[j-1]
			}
		}
	}

	return int(dp[m])
}