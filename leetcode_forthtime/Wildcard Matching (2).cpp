class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = 0;
        int indexi = 0;
        int indexj = 0;
        bool star = false;
        while(s[i])
        {
            if(!p[j])
            {
                if(star)
                    indexi++;
                else
                    return false;
                i = indexi;
                j = indexj;
            }
            else if(s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else if(p[j] =='*')
            {
                while(p[j] && p[j] == '*')
                    j++;
                indexi = i;
                indexj = j+1;
                star = true;
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
        while(p[j] && p[j] == '*')
            j++;
        return p[j] == '\0';
    }
};