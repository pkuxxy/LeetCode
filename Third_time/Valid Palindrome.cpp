class Solution {
public:
    bool isAn(char c)
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = s.size()-1;
        while(l < r)
        {
            if(!isAn(s[l]))
            {
                l++;
                continue;
            }
            if(!isAn(s[r]))
            {
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};