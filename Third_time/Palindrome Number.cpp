class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        int pow = 1;
        while(x/10 >= pow)
            pow *= 10;
        while(x)
        {
            if(x/pow != x%10)
                return false;
            x = (x%pow)/10;
            pow /= 100;
        }
        return true;
    }
};