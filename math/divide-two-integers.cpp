class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isPositive = (dividend >= 0) == (divisor >= 0);

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;
        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            n -= temp;
            ans += count;
        }

        return isPositive ? ans : -ans;
    }
};
