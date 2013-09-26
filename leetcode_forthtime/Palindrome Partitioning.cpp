class Solution {
public:
    vector<vector<string>> ret;
    bool isPalin(string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void dfs(string s, int index, int len, vector<string>& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < len; i++)
        {
            if(isPalin(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                dfs(s, i+1, len, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int mai() function
        ret.clear();
        int len = s.size();
        if(!len)
            return ret;
        vector<string> path;
        dfs(s, 0, len, path);
        return ret;
    }
};