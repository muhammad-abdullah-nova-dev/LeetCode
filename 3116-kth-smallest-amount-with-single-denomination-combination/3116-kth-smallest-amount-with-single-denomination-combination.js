var findKthSmallest = function(coins, k) {

    function gcd(a, b) {
        while (b !== 0n) {
            let temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    function lcm(a, b) {
        return (a / gcd(a, b)) * b;
    }

    function count(x) {
        let ans = 0n;
        let n = coins.length;

        for (let mask = 1; mask < (1 << n); mask++) {

            let L = 1n;
            let bits = 0;
            let valid = true;

            for (let i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, BigInt(coins[i]));

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            let ways = x / L;

            if (bits % 2 === 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    let minCoin = Math.min(...coins);

    let low = 1n;
    let high = BigInt(minCoin) * BigInt(k);

    while (low < high) {

        let mid = low + (high - low) / 2n;

        if (count(mid) >= BigInt(k))
            high = mid;
        else
            low = mid + 1n;
    }

    return Number(low);
};