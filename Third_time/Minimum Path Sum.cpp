class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = grid.size();
        if(!len1)
            return 0;
        int len2 = grid[0].size();
        vector<int> ret(len2);
        ret[0] = grid[0][0];
        for(int i = 1; i < len2; i++)
        {
            ret[i] = ret[i-1] + grid[0][i];
        }
        for(int i = 1;i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(j == 0)
                    ret[j] += grid[i][j];
                else
                    ret[j] = min(ret[j-1], ret[j]) + grid[i][j];
            }
        }
        return ret[len2-1];
    }
};