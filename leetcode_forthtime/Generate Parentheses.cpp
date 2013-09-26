class Solution {
public:
    vector<string> ret;
    void dfs(int left, int right, string& path)
    {
        if(!left && !right)
        {
            ret.push_back(path);
            return;
        }
        if(left)
        {
            path.push_back('(');
            dfs(left-1, right, path);
            path.pop_back();
        }
        if(right > left)
        {
            path.push_back(')');
            dfs(left, right-1, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(n <= 0)
            return ret;
        string path;
        dfs(n, n, path);
        return ret;
    }
};