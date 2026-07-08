class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> nextNonZero(n), prevNonZero(n), rank(n, -1);

        vector<int> digits;
        vector<long long> prefSum(1, 0), prefNum(1, 0), pow10(1, 1);

        // next non-zero
        int nxt = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') nxt = i;
            nextNonZero[i] = nxt;
        }

        // prev non-zero
        int prv = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') prv = i;
            prevNonZero[i] = prv;
        }

        // compressed digits + rank
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                rank[i] = digits.size();
                digits.push_back(s[i] - '0');

                prefSum.push_back(prefSum.back() + digits.back());
                prefNum.push_back((prefNum.back() * 10 + digits.back()) % MOD);
                pow10.push_back(pow10.back() * 10 % MOD);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int leftPos = nextNonZero[l];
            int rightPos = prevNonZero[r];

            if (leftPos == -1 || rightPos == -1 || leftPos > rightPos) {
                ans.push_back(0);
                continue;
            }

            int L = rank[leftPos];
            int R = rank[rightPos];

            int len = R - L + 1;

            long long num =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back(num * sum % MOD);
        }

        return ans;
    }
};