package main

func validSequence(word1 string, word2 string) []int {

	n := len(word1)
	m := len(word2)

	// nxtIdx[i][c] = first index >= i
	// where character c occurs in word1
	nxtIdx := make([][]int, n+1)

	for i := 0; i <= n; i++ {
		nxtIdx[i] = make([]int, 26)

		for j := 0; j < 26; j++ {
			nxtIdx[i][j] = -1
		}
	}

	for i := n - 1; i >= 0; i-- {

		// Copy next row
		for c := 0; c < 26; c++ {
			nxtIdx[i][c] = nxtIdx[i+1][c]
		}

		nxtIdx[i][int(word1[i]-'a')] = i
	}

	// suff[j] = position where word2[j]
	// can be matched from the right
	suff := make([]int, m)

	for i := 0; i < m; i++ {
		suff[i] = -1
	}

	k := m - 1

	for i := n - 1; i >= 0 && k >= 0; i-- {

		if word1[i] == word2[k] {
			suff[k] = i
			k--
		}
	}

	ans := make([]int, 0, m)

	i := 0
	j := 0

	used := false

	for i < n && j < m {

		idx := nxtIdx[i][int(word2[j]-'a')]

		// Mismatch already used
		if used {

			if idx == -1 {
				return []int{}
			}

			if j < m-1 && suff[j+1] <= idx {
				return []int{}
			}

			ans = append(ans, idx)

			i = idx + 1
			j++

		} else {

			// Exact match
			if word1[i] == word2[j] {

				ans = append(ans, i)

				i++
				j++

			} else if j == m-1 ||
				(suff[j+1] != -1 && i < suff[j+1]) {

				// Use our one mismatch
				used = true

				ans = append(ans, i)

				i++
				j++

			} else {

				// Current index cannot be used
				i++
			}
		}
	}

	if len(ans) == m {
		return ans
	}

	return []int{}
}