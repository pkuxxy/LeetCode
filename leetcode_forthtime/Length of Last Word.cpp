class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s)
            return 0;
        int len = 0;
        int lastlen = 0;
        for(;*s;s++)
        {
            if(*s == ' ')
            {
                lastlen = (len == 0) ? lastlen:len;
                len = 0;
            }
            else
                len++;
        }
        lastlen = (len == 0) ? lastlen:len;
        return lastlen;
    }
};