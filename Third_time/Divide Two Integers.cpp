class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!divisor)
            return 0;
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        unsigned long a = abs(dividend);
        unsigned long b = abs(divisor);
        vector<unsigned long> f(40, 0);
        f[0] = b;
        int size = 1;
        while(f[size-1] < a)
        {
            f[size] = f[size-1]+f[size-1];
            size++;
        }
        int ret = 0;
        while(size--)
        {
            ret <<= 1;
            if(a >= f[size])
            {
                ret |= 1;
                a -= f[size];
            }
            else
            {
                ret |= 0;
            }
        }
        return neg?-ret:ret;
    }
};