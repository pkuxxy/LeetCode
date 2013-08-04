class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        vector<vector<bool>> p(len, vector<bool>(len, false));
        vector<int> ret(len, 0);
        for(int i = 0; i < len; i++)
        {
            ret[i] = i;
        }
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(s[i] == s[j] && (i-j<=2 || p[j+1][i-1]))
                {
                    p[j][i] = true;
                    if(j == 0)
                        ret[i] = 0;
                    else
                        ret[i] = min(ret[i],ret[j-1]+1);
                }
            }
        }
        return ret[len-1];
    }
};