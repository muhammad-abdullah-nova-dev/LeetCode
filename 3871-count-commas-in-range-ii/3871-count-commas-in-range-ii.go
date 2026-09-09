func countCommas(n int64) int64 {
	start := int64(1000)

	commas := int64(1)

	var answer int64

	for start <= n {
		var end int64

		if start > n/1000 {
			end = n
		} else {
			end = start*1000 - 1
		}

		count := end - start + 1

		answer += count * commas

		start *= 1000

		commas++
	}

	return answer
}