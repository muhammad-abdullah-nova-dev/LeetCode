func maximumLengthSubstring(s string) int {
	freq := make([]int, 26)

	left := 0

	ans := 0

	for right := 0; right < len(s); right++ {
		index := int(s[right] - 'a')
		freq[index]++

		for freq[index] > 2 {
			freq[int(s[left]-'a')]--

			left++
		}

		length := right - left + 1
		if length > ans {
			ans = length
		}
	}

	return ans
}