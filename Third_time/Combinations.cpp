class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int index, int n, int count, int k, vector<int>& path)
    {
        if(count == k)
        {
            ret.push_back(path);
            return;
        }
        if(index > n)
            return;
        for(int i = index; i <= n; i++)
        {
            path.push_back(i);
            dfs(i+1, n, count+1, k, path);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(n < k || n <=0 || k <= 0)
            return ret;
        vector<int> path;
        dfs(1,n,0,k,path);
        return ret;
    }
};