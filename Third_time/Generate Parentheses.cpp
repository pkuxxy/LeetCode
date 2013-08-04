class Solution {
public:
    vector<string> ret;
    void dfs(int l, int r, string& path)
    {
        if(!l && !r)
        {
            ret.push_back(path);
            return;
        }
        if(l > 0)
        {
            path.push_back('(');
            dfs(l-1, r, path);
            path.pop_back();
        }
        if(r > 0 && l < r)
        {
            path.push_back(')');
            dfs(l, r-1, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        string path;
        dfs(n,n,path);
        return ret;
    }
};