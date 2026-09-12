/**
 * @param {number[][]} intervals
 * @return {number[]}
 */
var maximumWeight = function(intervals) {
    const n = intervals.length;
    const K = 4;

    const a = intervals.map((x, i) => [x[0], x[1], x[2], i]);

    a.sort((x, y) => x[1] - y[1]);

    const ends = a.map(x => x[1]);

    const dp = Array.from({ length: K + 1 }, () => Array(n + 1).fill(null));

    for (let i = 0; i <= n; i++) {
        dp[0][i] = { score: 0, ids: [] };
    }

    const better = (a, b) => {
        if (a === null) return false;
        if (b === null) return true;

        if (a.score !== b.score) return a.score > b.score;

        const len = Math.min(a.ids.length, b.ids.length);

        for (let i = 0; i < len; i++) {
            if (a.ids[i] !== b.ids[i]) {
                return a.ids[i] < b.ids[i];
            }
        }

        return a.ids.length < b.ids.length;
    };

    const lowerBound = (length, target) => {
        let lo = 0;
        let hi = length;

        while (lo < hi) {
            const mid = lo + Math.floor((hi - lo) / 2);

            if (ends[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    };

    for (let i = 1; i <= n; i++) {
        const [left, , weight, originalIndex] = a[i - 1];

        const p = lowerBound(i - 1, left);

        for (let k = 1; k <= K; k++) {
            dp[k][i] = dp[k][i - 1];

            if (dp[k - 1][p] !== null) {
                const ids = [...dp[k - 1][p].ids, originalIndex];

                ids.sort((x, y) => x - y);

                const take = {
                    score: dp[k - 1][p].score + weight,
                    ids
                };

                if (better(take, dp[k][i])) {
                    dp[k][i] = take;
                }
            }
        }
    }

    let answer = null;

    for (let k = 1; k <= K; k++) {
        if (better(dp[k][n], answer)) {
            answer = dp[k][n];
        }
    }

    return answer.ids;
};