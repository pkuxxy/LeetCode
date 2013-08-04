class Solution {
public:
    vector<string> ret;
    void dfs(string s, int index, int len, int count, vector<string>& path)
    {
        if(index >= len)
        {
            if(count == 4)
            {
                string cur(path[0]);
                //cur.push_back('.');
                for(int i = 1; i < 4; i++)
                {
                    cur.push_back('.');
                    cur.append(path[i]);
                }
                ret.push_back(cur);
            }
            return;
        }
        for(int i = index; i < len && i < index+3; i++)
        {
            string cur(s, index, i-index+1);
            if(cur.size() > 1 && cur[0] == '0')
                continue;
            int n = atoi(cur.c_str());
            if(n >= 0 && n <= 255)
            {
                path.push_back(cur);
                dfs(s, i+1, len, count+1, path);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = s.size();
        if(!len || len > 12)
            return ret;
        vector<string> path;
        dfs(s, 0, len, 0, path);
        return ret;
    }
};