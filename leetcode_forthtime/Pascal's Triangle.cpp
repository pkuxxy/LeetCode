class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        if(numRows <= 0)
            return ret;
        ret.push_back(vector<int>(1,1));
        for(int i = 1; i < numRows; i++)
        {
            vector<int> cur(i+1);
            cur[0] = 1;
            for(int j = 1; j < i;j ++)
            {
                cur[j] = ret[i-1][j]+ret[i-1][j-1];
            }
            cur[i] = 1;
            ret.push_back(cur);
        }
        return ret;
    }
};