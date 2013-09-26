class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned long a = abs(dividend);
        unsigned long b = abs(divisor);
        bool sign = (dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0);
        int offset = 0;
        while((a>>1) >= b)
        {
            b += b;
            offset++;
        }
        int ret = 0;
        for(int i = offset; i >= 0; i--)
        {
            if(a >= b)
            {
                ret |= (1<<i);
                a -= b;
            }
            b >>= 1;
        }
        return sign?ret:-ret;
    }
};