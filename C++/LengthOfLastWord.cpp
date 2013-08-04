#include<string.h>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s) - 1;
		int count = 0;
		while(len >= 0 && s[len] == ' ')
			len--;
		
		for(int i = len; i >=0; i--)
		{
			if(s[i] == ' ')
				break;
			count++;
		}
		return count;
    }
};