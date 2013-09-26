class Solution {
public:
    string str[10];
    Solution()
    {
        str[2] = "abc";
        str[3] = "def";
        str[4] = "ghi";
        str[5] = "jkl";
        str[6] = "mno";
        str[7] = "pqrs";
        str[8] = "tuv";
        str[9] = "wxyz";
    }
    vector<string> ret;
    void dfs(string digits, int index, int len, string& path)
    {
        if(index == len)
        {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < str[digits[index] - '0'].size(); i++)
        {
            path.push_back(str[digits[index] - '0'][i]);
            dfs(digits, index+1, len, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        int len = digits.size();
        string path;
        dfs(digits, 0, len, path);
        return ret;
    }
};