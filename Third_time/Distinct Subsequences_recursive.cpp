class Solution {
public:
    int ret;
    void dfs(string s, int ss, int lens, string t, int ts, int lent)
    {
        if(ts == lent)
        {
            ret++;
            return;
        }
        for(int i = ss; i < lens; i++)
        {
            if(s[i] == t[ts])
                dfs(s, i+1, lens, t, ts+1, lent);
        }
    }
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        dfs(S, 0, S.size(), T, 0, T.size());
        return ret;
    }
};