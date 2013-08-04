class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int>& s, int index, int size, vector<int>& path)
    {
        ret.push_back(path);
        if(index >= size)
            return;
        for(int i = index; i < size; i++)
        {
            if(i != index && s[i] == s[i-1])
                continue;
            path.push_back(s[i]);
            dfs(s, i+1, size, path);
            path.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S, 0, S.size(), path);
        return ret;
    }
};