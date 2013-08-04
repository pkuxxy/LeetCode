class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!divisor)
            return 0;
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long long a = dividend;
    	long long b = divisor;
		if(a < 0)
			a = -a;
		if(b < 0)
			b = -b;
        
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
        return neg?-ret:ret;
    }
};