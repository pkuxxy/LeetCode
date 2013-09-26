class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int>& num, int index, int len, int target, vector<int>& path)
    {
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }
        if(target < 0 || index == len)
            return;
        for(int i = index; i < len; i++)
        {
            if(i != index && num[i] == num[i-1])
                continue;
            path.push_back(num[i]);
            dfs(num, i+1, len, target-num[i], path);
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = num.size();
        sort(num.begin(), num.end());
        vector<int> path;
        dfs(num, 0, len, target, path);
        return ret;
    }
};