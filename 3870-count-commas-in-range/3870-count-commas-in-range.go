func countCommas(n int) int {
	answer := 0
	threshold := 1000

	for threshold <= n {
		answer += n - threshold + 1

		threshold *= 1000
	}

	return answer
}