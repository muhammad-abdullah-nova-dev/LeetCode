class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int newVar = n;

        while (newVar != 0) {
            int temp = newVar % 10;
            sum += temp;
            product *= temp;
            newVar /= 10;
        }

        int newSum = sum + product;

        return n % newSum == 0;
    }
};