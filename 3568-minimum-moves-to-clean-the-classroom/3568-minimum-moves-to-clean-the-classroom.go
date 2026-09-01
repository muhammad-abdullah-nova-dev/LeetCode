func minMoves(classroom []string, energy int) int {
	m := len(classroom)
	n := len(classroom[0])

	id := make([][]int, m)
	for r := 0; r < m; r++ {
		id[r] = make([]int, n)

		for c := 0; c < n; c++ {
			id[r][c] = -1
		}
	}

	k := 0
	sr, sc := 0, 0

	for r := 0; r < m; r++ {
		for c := 0; c < n; c++ {
			if classroom[r][c] == 'S' {
				sr, sc = r, c
			} else if classroom[r][c] == 'L' {
				id[r][c] = k
				k++
			}
		}
	}

	if k == 0 {
		return 0
	}

	totalMask := (1 << k) - 1

	best := make([][][]int, m)

	for r := 0; r < m; r++ {
		best[r] = make([][]int, n)

		for c := 0; c < n; c++ {
			best[r][c] = make([]int, 1<<k)

			for mask := 0; mask < (1 << k); mask++ {
				best[r][c][mask] = -1
			}
		}
	}

	type State struct {
		r, c   int
		mask   int
		energy int
		moves  int
	}

	queue := make([]State, 0)
	head := 0

	best[sr][sc][0] = energy
	queue = append(queue, State{sr, sc, 0, energy, 0})

	dr := [4]int{-1, 1, 0, 0}
	dc := [4]int{0, 0, -1, 1}

	for head < len(queue) {
		cur := queue[head]
		head++

		for d := 0; d < 4; d++ {
			nr := cur.r + dr[d]
			nc := cur.c + dc[d]

			if nr < 0 || nr >= m || nc < 0 || nc >= n {
				continue
			}

			if classroom[nr][nc] == 'X' {
				continue
			}

			ne := cur.energy - 1

			if ne < 0 {
				continue
			}

			nmask := cur.mask

			if classroom[nr][nc] == 'R' {
				ne = energy
			}

			if classroom[nr][nc] == 'L' {
				nmask |= 1 << id[nr][nc]
			}

			if nmask == totalMask {
				return cur.moves + 1
			}

			if ne <= best[nr][nc][nmask] {
				continue
			}

			best[nr][nc][nmask] = ne

			queue = append(queue, State{
				nr, nc, nmask, ne, cur.moves + 1,
			})
		}
	}

	return -1
}