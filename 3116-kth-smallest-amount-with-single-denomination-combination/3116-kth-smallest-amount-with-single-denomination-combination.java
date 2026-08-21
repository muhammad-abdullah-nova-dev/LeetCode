class Solution {

    long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    long count(long x, int[] coins) {
        long ans = 0;
        int n = coins.length;

        for (int mask = 1; mask < (1 << n); mask++) {
            long L = 1;
            int bits = 0;
            boolean valid = true;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            long ways = x / L;

            if (bits % 2 == 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    public long findKthSmallest(int[] coins, int k) {
        long minCoin = coins[0];

        for (int coin : coins) {
            minCoin = Math.min(minCoin, coin);
        }

        long low = 1;
        long high = minCoin * (long) k;

        while (low < high) {
            long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
}