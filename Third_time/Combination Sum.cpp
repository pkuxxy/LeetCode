class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &candidates, int index, int len, int target, vector<int>& path)
    {
        if(!target)
        {
            ret.push_back(path);
            return;
        }
        if(index == len)
            return;
        int count = target/candidates[index];
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j < i; j++)
            {
                path.push_back(candidates[index]);
            }
            dfs(candidates, index+1, len, target-i*candidates[index], path);
            for(int j = 0; j < i; j++)
            {
                path.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = candidates.size();
        if(!len && target <= 0)
            return ret;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, 0, len, target, path);
        return ret;
    }
};