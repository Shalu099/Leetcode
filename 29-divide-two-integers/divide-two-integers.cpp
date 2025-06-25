class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;  // ✅ Avoid division by zero
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;  // ✅ Overflow case

        long a = labs(dividend);
        long b = labs(divisor);
        long result = 0;

        while (a >= b) {
            long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        result = ((dividend > 0) == (divisor > 0)) ? result : -result;

        return result;
    }
};
