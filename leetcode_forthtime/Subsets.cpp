class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int>& s, int index, int len, vector<int>& path)
    {
        ret.push_back(path);
        if(index == len)
        {
            return;
        }
        for(int i = index; i < len; i++)
        {
            path.push_back(s[i]);
            dfs(s, i+1, len, path);
            path.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = S.size();
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S, 0, len, path);
        return ret;
    }
};