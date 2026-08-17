/**
 * @param {number[]} stoneValue
 * @return {number}
 */
var stoneGameV = function(stoneValue) {
    const n = stoneValue.length;

    const prefix = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    const leftBest = Array.from(
        { length: n },
        () => new Array(n).fill(0)
    );

    const rightBest = Array.from(
        { length: n },
        () => new Array(n).fill(0)
    );

    const leftPtr = new Array(n);

    const rightPtr = new Array(n);

    for (let i = 0; i < n; i++) {
        leftBest[i][i] = stoneValue[i];
        rightBest[i][i] = stoneValue[i];

        leftPtr[i] = i - 1;

        rightPtr[i] = i;
    }

    for (let len = 2; len <= n; len++) {
        for (let l = 0; l + len <= n; l++) {
            const r = l + len - 1;

            const total = prefix[r + 1] - prefix[l];

            while (leftPtr[l] + 1 <= r - 1) {
                const k = leftPtr[l] + 1;
                const leftSum = prefix[k + 1] - prefix[l];

                if (2 * leftSum > total) {
                    break;
                }

                leftPtr[l]++;
            }

            while (rightPtr[l] <= r - 1) {
                const k = rightPtr[l];
                const leftSum = prefix[k + 1] - prefix[l];

                if (2 * leftSum >= total) {
                    break;
                }

                rightPtr[l]++;
            }

            let best = 0;

            if (leftPtr[l] >= l) {
                best = leftBest[l][leftPtr[l]];
            }

            if (rightPtr[l] <= r - 1) {
                best = Math.max(
                    best,
                    rightBest[rightPtr[l] + 1][r]
                );
            }

            dp[l][r] = best;

            leftBest[l][r] = Math.max(
                leftBest[l][r - 1],
                dp[l][r] + total
            );

            rightBest[l][r] = Math.max(
                rightBest[l + 1][r],
                dp[l][r] + total
            );
        }
    }

    return dp[0][n - 1];
};