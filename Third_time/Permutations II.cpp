class Solution {
public:
vector<vector<int> > ret;
vector<int> pos;
    void dfs(vector<int>& num, int index, int len, vector<bool>& used)
    {
        if(index == len)
        {
            ret.push_back(pos);
            return;
        }
        for(int i = 0; i < len; i++)
        {
            if((i != 0 && num[i] == num[i-1] && !used[i-1]) || used[i])
                continue;
    		pos[index] = num[i];
            used[i] = true;
            dfs(num, index+1, len, used);
            used[i] = false;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        pos.clear();
        int len = num.size();
        if(!len)
            return ret;
		sort(num.begin(), num.end());
		pos.resize(len);
        vector<bool> used(len, false);
        dfs(num, 0, len, used);
        return ret;
    }
};