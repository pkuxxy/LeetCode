class Solution {
public:
static map<char, string> vm;
static void init()
{
    vm['2'] = "abc";
	vm['3'] = "def";
	vm['4'] = "ghi";
	vm['5'] = "jkl";
	vm['6'] = "mno";
	vm['7'] = "pqrs";
	vm['8'] = "tuv";
	vm['9'] = "wxyz";
}
    vector<string> ret;
    void dfs(vector<string>& strs, int s, int len, string& path)
    {
        if(s >= len)
        {
            ret.push_back(path);
            return;
        }
        string cur = strs[s];
        for(int i = 0; i < cur.size(); i++)
        {
            path.push_back(cur[i]);
            dfs(strs, s+1, len, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        init();
        int len = digits.size();
        vector<string> strs;
        for(int i = 0; i < len; i++)
        {
            strs.push_back(vm[digits[i]]);
        }
        string path;
        dfs(strs, 0, strs.size(), path);
        return ret;
    }
};
map<char, string> Solution::vm;