func lexGreaterPermutation(s string, target string) string {
	count := make([]int, 26)
	for i := 0; i < len(s); i++ {
		count[s[i]-'a']++
	}

	n := len(s)
	matched := 0

	for matched < n && count[target[matched]-'a'] > 0 {
		count[target[matched]-'a']--
		matched++
	}

	start := n - 1
	if matched < n {
		start = matched
	}

	for i := start; i >= 0; i-- {
		if i < matched {
			count[target[i]-'a']++
		}

		bigger := -1
		for ch := int(target[i]-'a') + 1; ch < 26; ch++ {
			if count[ch] > 0 {
				bigger = ch
				break
			}
		}

		if bigger != -1 {
			count[bigger]--

			answer := make([]byte, 0, n)
			answer = append(answer, target[:i]...)

			answer = append(answer, byte('a'+bigger))

			for ch := 0; ch < 26; ch++ {
				for count[ch] > 0 {
					answer = append(answer, byte('a'+ch))
					count[ch]--
				}
			}

			return string(answer)
		}
	}

	return ""
}