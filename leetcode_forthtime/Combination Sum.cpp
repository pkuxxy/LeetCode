class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<int> &cans, int index, int len, int target, vector<int>& path)
    {
        if(target == 0)
        {
            vector<int> list;
            for(int i = 0 ; i < len; i++)
            {
                for(int j = 0; j < path[i]; j++)
                {
                    list.push_back(cans[i]);
                }
            }
            ret.push_back(list);
            return;
        }
        if(target < 0 || index == len)
            return;
        for(int i = 0; i <= target/cans[index]; i++)
        {
            path.push_back(i);
            dfs(cans, index+1, len, target-i*cans[index], path);
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, 0, len, target, path);
        return ret;
    }
};