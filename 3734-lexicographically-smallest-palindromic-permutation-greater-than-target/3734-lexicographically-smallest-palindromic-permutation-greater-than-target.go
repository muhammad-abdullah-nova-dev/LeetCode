func lexPalindromicPermutation(str string, target string) string {
	freq := make([]int, 26)
	for _, b := range str {
		freq[b-'a']++
	}

	check := func() bool {
		for _, v := range freq {
			if v < 0 {
				return false
			}
		}
		return true
	}

	center := ""
	for i, v := range freq {
		if v%2 == 0 {
			continue
		}
		if center != "" {
			return ""
		}
		center = string('a' + byte(i))
		freq[i]--
	}

	sz := len(str)
	half := sz / 2
	for _, b := range target[:half] {
		freq[b-'a'] -= 2
	}

	if check() {
		head := target[:half]
		tmp := []byte(head)
		slices.Reverse(tmp)
		tail := center + string(tmp)
		if tail > target[half:] {
			return head + tail
		}
	}

	for i := half - 1; i >= 0; i-- {
		w := target[i] - 'a'
		freq[w] += 2
		if !check() {
			continue
		}

		for j := w + 1; j < 26; j++ {
			if freq[j] == 0 {
				continue
			}

			freq[j] -= 2
			result := []byte(target[:i+1])
			result[i] = 'a' + byte(j)

			for k, v := range freq {
				ch := string('a' + byte(k))
				result = append(result, strings.Repeat(ch, v/2)...)
			}

			part := slices.Clone(result)
			slices.Reverse(part)
			result = append(result, center...)
			result = append(result, part...)

			return string(result)
		}
	}

	return ""
}