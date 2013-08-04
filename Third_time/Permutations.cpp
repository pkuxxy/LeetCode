class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int>& num, int index, int len, vector<bool>& used, vector<int>& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < len ;i++)
        {
            if(!used[i])
            {
                used[i] = true;
                path.push_back(num[i]);
                dfs(num, index+1, len, used, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = num.size();
        if(!len)
            return ret;
        vector<bool> used(len, false);
        vector<int> path;
        dfs(num, 0, len, used, path);
        return ret;
    }
};