class Solution {
public:
    vector<string> ret;
    void dfs(string s, int index, int len, int count, vector<string> path)
    {
        if(count < 0)
            return;
        if(index == len)
        {
            if(count == 0)
            {
                string cur = path[0];
                for(int i = 1; i < 4; i++)
                    cur += "."+path[i];
                ret.push_back(cur);
            }
            return;
        }
        int sum = 0;
        for(int i = index; i < len && i < index+3; i++)
        {
            sum *= 10;
            sum += s[i] - '0';
            if((i != index && s[index] == '0') || sum > 255)
                break;
            path.push_back(s.substr(index, i-index+1));
            dfs(s, i+1, len, count-1, path);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = s.size();
        if(len < 4 || len > 12)
            return ret;
        vector<string> path;
        dfs(s, 0, len, 4, path);
        return ret;
    }
};