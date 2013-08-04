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
        int size = 0;
        while((b<<size) <= a)
        {
            size++;
        }
        size--;
        int ret = 0;
        for(int i = size; i >= 0; i--)
        {
            if((b<<i) <= a)
            {
                a -= (b<<i);
                ret += (1<<i);
            }
         
        }
        return ret;
    }
};