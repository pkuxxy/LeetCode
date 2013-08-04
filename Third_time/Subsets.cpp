class Solution {
public:
vector<vector<int> > ret;
    void dfs(vector<int>&s, int index, int len, vector<int>& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        dfs(s, index+1, len, path);
        path.push_back(s[index]);
        dfs(s, index+1, len, path);
        path.pop_back();
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = S.size();
        if(!len)
            return ret;
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S,0,len,path);
        return ret;
    }
};