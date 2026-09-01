/**
 * @param {string[]} classroom
 * @param {number} energy
 * @return {number}
 */
var minMoves = function(classroom, energy) {
    const m = classroom.length;
    const n = classroom[0].length;

    const id = Array.from({ length: m }, () => Array(n).fill(-1));

    let k = 0;
    let sr = 0;
    let sc = 0;

    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            if (classroom[r][c] === 'S') {
                sr = r;
                sc = c;
            } else if (classroom[r][c] === 'L') {
                id[r][c] = k++;
            }
        }
    }

    if (k === 0) return 0;

    const totalMask = (1 << k) - 1;

    const best = Array.from(
        { length: m },
        () => Array.from(
            { length: n },
            () => new Int16Array(1 << k).fill(-1)
        )
    );

    const queue = [[sr, sc, 0, energy, 0]];

    let head = 0;

    best[sr][sc][0] = energy;

    const dr = [-1, 1, 0, 0];
    const dc = [0, 0, -1, 1];

    while (head < queue.length) {
        const [r, c, mask, e, moves] = queue[head++];

        for (let d = 0; d < 4; d++) {
            const nr = r + dr[d];
            const nc = c + dc[d];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (classroom[nr][nc] === 'X')
                continue;

            let ne = e - 1;

            if (ne < 0)
                continue;

            let nmask = mask;

            if (classroom[nr][nc] === 'R') {
                ne = energy;
            }

            if (classroom[nr][nc] === 'L') {
                nmask |= (1 << id[nr][nc]);
            }

            if (nmask === totalMask) {
                return moves + 1;
            }

            if (ne <= best[nr][nc][nmask])
                continue;

            best[nr][nc][nmask] = ne;

            queue.push([nr, nc, nmask, ne, moves + 1]);
        }
    }

    return -1;
};