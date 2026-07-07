class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string s = to_string(n);
        long long x = 0;
        long long sum = 0;

        for (char c : s) {
            int digit = c - '0';

            if (digit != 0) {
                x = x * 10 + digit;
                sum += digit;
            }
        }

        return x * sum;
    }
};