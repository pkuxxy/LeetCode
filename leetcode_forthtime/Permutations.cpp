class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<int>& num, int index, int len)
    {
        if(index == len)
            ret.push_back(num);
        for(int i = index; i < len; i++)
        {
            swap(num[i], num[index]);
            dfs(num, index+1, len);
            swap(num[i], num[index]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        dfs(num, 0, num.size());
        return ret;
    }
};