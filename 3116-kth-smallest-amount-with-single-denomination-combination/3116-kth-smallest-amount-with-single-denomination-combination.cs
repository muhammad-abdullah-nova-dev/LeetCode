public class Solution {

    long GCD(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long LCM(long a, long b) {
        return a / GCD(a, b) * b;
    }

    long Count(long x, int[] coins) {
        long ans = 0;
        int n = coins.Length;

        for (int mask = 1; mask < (1 << n); mask++) {
            long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    bits++;

                    L = LCM(L, coins[i]);

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long ways = x / L;

            if (bits % 2 == 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    public long FindKthSmallest(int[] coins, int k) {
        int minCoin = coins[0];

        foreach (int coin in coins) {
            minCoin = Math.Min(minCoin, coin);
        }

        long low = 1;
        long high = (long)minCoin * k;

        while (low < high) {
            long mid = low + (high - low) / 2;

            if (Count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
}