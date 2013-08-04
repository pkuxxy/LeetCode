class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s)
            return 0;
        int len = strlen(s);
        int end = len-1;
        while(end >= 0 && s[end] == ' ')
            end--;
        for(int i = end-1; i>= 0; i--)
        {
            if(s[i] == ' ')
                return end - i;
        }
        return end >= 0?(end+1):0;
    }
};