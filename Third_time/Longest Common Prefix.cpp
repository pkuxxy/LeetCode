class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;
        if(!strs.size())
            return ret;
        for(int i = 0; i < strs[0].size(); i++)
        {
            int j = 1;
            for(; j < strs.size();j++)
            {
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])
                    break;
            }
            if(j == strs.size())
                ret.push_back(strs[0][i]);
            else
                break;
        }
        return ret;
    }
};