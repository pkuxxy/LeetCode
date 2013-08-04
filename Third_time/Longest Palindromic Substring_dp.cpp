class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return s;
        vector<vector<bool>> p(len, vector<bool>(len, false));
        string ret;
        for(int i = 1; i <= len; i++)
        {
            for(int j = 0; j <= len-i; j++)
            {
                int k = j+i-1;
                if(s[j] == s[k] && (k-j<=2 || p[j+1][k-1]))
                {
                    p[j][k] = true;
                    ret = s.substr(j, i);
                }
            }
        }
        return ret;
    }
};