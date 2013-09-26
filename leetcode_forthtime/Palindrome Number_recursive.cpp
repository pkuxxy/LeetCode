class Solution {
public:
    bool helper(int x, int& y)
    {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        if(helper(x/10, y) && (x%10 == y%10))
        {
            y /= 10;
            return true;
        }
        return false;
    }
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return helper(x, x);
    }
};