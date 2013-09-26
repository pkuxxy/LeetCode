class Solution {
public:
    vector<vector<int> > ret;
    void dfs(map<int, int> m, int index, int len, vector<int>& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            if(iter->second)
            {
                path.push_back(iter->first);
                iter->second--;
                dfs(m, index+1, len, path);
                iter->second++;
                path.pop_back();
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        map<int, int> m;
        for(int i = 0; i < num.size(); i++)
            m[num[i]]++;
        vector<int> path;
        dfs(m, 0, num.size(), path);
        return ret;
    }
};