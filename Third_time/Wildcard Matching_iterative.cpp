class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lens = strlen(s);
        int lenp = strlen(p);
        int i = 0;
        int j = 0;
        int indexi = 0;
        int indexj = 0;
        bool star = false;
        while(i < lens)
        {
            if(j == lenp)
            {
                if(star)
                    indexi++;
                else 
                    return false;
                i = indexi;
                j = indexj;
            }
            else if(p[j] == '*')
            {
                star = true;
                while(j < lenp && p[j] == '*')
                    j++;
                if(j == lenp)
                    return true;
                indexi = i;
                indexj = j;
            }
            else if(s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else
            {
                if(star)
                    indexi++;
                else
                    return false;
                i = indexi;
                j = indexj;
            }
        }
        while(j < lenp && p[j] == '*')
            j++;
        return j == lenp;
    }
};