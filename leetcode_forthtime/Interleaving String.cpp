class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 + len2 != s3.size())
            return false;
        vector<vector<bool>> f(len1+1, vector<bool>(len2+1, false));
        for(int i = 0; i <= len1; i++)
        {
            f[i][0] = (s1.substr(0, i) == s3.substr(0,i));
        }
        for(int i = 1; i <= len2; i++)
            f[0][i] = (s2.substr(0,i) == s3.substr(0, i));
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(s1[i-1] == s3[i+j-1] && f[i-1][j])
                    f[i][j] = true;
                if(s2[j-1] == s3[i+j-1] && f[i][j-1])
                    f[i][j] = true;
            }
        }
        return f[len1][len2];
    }
};