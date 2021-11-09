class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n = dividend;
        long long m = divisor;
        int sign = n < 0 ^ m < 0 ? -1 : 1;
        n = abs(n);
        m = abs(m);
        long long q = 0;
        long long t = 0;
        for(long long i=31;i>=0;i--){
            if(t + (m << i) <= n){
                t += m<<i;
                q = q | 1ll << i;
            }
        }
        if(sign < 0)q= -q;
        return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
    }
};