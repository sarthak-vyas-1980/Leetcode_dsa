class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool flag = true;
        if(dividend >= 0 && divisor < 0) flag = false;
        if(dividend < 0 && divisor >= 0) flag = false;

        long n = labs((long)dividend);
        long d = labs((long)divisor), quotient = 0;

        while(d <= n){
            int count = 0;
            while(n >= d<<(count+1)) count++;
            quotient += (1LL<<count);
            n -= d<<count;
        }
        if(quotient > INT_MAX && flag) return INT_MAX;
        if(quotient > INT_MAX && !flag) return INT_MIN;
        return flag ? quotient : -quotient;
    }
};