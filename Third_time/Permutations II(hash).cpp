class Solution {
public:
vector<vector<int> > ret;
map<int, int> m;
    void dfs(vector<int>& num, int index, int len, map<int, int>& m, vector<int>& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        map<int, int>::iterator iter = m.begin();
        for(;iter != m.end(); iter++)
        {
            if(iter->second)
            {
                iter->second--;
                path.push_back(iter->first);
                dfs(num,index+1, len, m, path);
                path.pop_back();
                iter->second++;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        m.clear();
        int len = num.size();
        if(!len)
            return ret;
		for(int i = 0; i < len; i++)
        {
            if(m.find(num[i]) == m.end())
            {
                m[num[i]] = 1;
            }
            else
                m[num[i]]++;
        }
        vector<int> path;
        dfs(num, 0, len, m, path);
        return ret;
    }
};