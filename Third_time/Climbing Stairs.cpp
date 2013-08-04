class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
        return 0;
        int a = 0;
        int b = 1;
        while(n--)
        {
            b += a;
            a = b - a;
        }
        return b;
    }
};