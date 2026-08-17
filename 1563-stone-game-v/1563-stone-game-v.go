func stoneGameV(stoneValue []int) int {
	n := len(stoneValue)

	prefix := make([]int64, n+1)

	for i := 0; i < n; i++ {
		prefix[i+1] = prefix[i] + int64(stoneValue[i])
	}

	dp := make([][]int, n)

	leftBest := make([][]int, n)

	rightBest := make([][]int, n)

	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		leftBest[i] = make([]int, n)
		rightBest[i] = make([]int, n)

		leftBest[i][i] = stoneValue[i]
		rightBest[i][i] = stoneValue[i]
	}

	leftPtr := make([]int, n)

	rightPtr := make([]int, n)

	for i := 0; i < n; i++ {
		leftPtr[i] = i - 1

		rightPtr[i] = i
	}

	for length := 2; length <= n; length++ {
		for l := 0; l+length <= n; l++ {
			r := l + length - 1

			total := prefix[r+1] - prefix[l]

			for leftPtr[l]+1 <= r-1 {
				k := leftPtr[l] + 1
				leftSum := prefix[k+1] - prefix[l]

				if 2*leftSum > total {
					break
				}

				leftPtr[l]++
			}

			for rightPtr[l] <= r-1 {
				k := rightPtr[l]
				leftSum := prefix[k+1] - prefix[l]

				if 2*leftSum >= total {
					break
				}

				rightPtr[l]++
			}

			best := 0

			if leftPtr[l] >= l {
				best = leftBest[l][leftPtr[l]]
			}

			if rightPtr[l] <= r-1 {
				candidate := rightBest[rightPtr[l]+1][r]

				if candidate > best {
					best = candidate
				}
			}

			dp[l][r] = best

			currentSum := int(total)
			leftCandidate := dp[l][r] + currentSum

			if leftBest[l][r-1] > leftCandidate {
				leftBest[l][r] = leftBest[l][r-1]
			} else {
				leftBest[l][r] = leftCandidate
			}

			rightCandidate := dp[l][r] + currentSum

			if rightBest[l+1][r] > rightCandidate {
				rightBest[l][r] = rightBest[l+1][r]
			} else {
				rightBest[l][r] = rightCandidate
			}
		}
	}

	return dp[0][n-1]
}