class Solution {
public:
    int helper(int x, int y)
    {
        if(!x)
            return y;
        return helper(x/10, y*10+x%10);
        
    }
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return helper(x, 0);
    }
};