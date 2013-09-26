class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = grid.size();
        if(!len1)
            return 0;
        int len2 = grid[0].size();
        vector<int> d(len2, 0);
        d[0] = grid[0][0];
        for(int i = 1; i < len2; i++)
        {
            d[i] = d[i-1]+grid[0][i];
        }
        for(int i = 1; i < len1; i++)
        {
            d[0] += grid[i][0];
            for(int j = 1; j < len2; j++)
            {
                d[j] = min(d[j]+grid[i][j],d[j-1]+grid[i][j]);
            }
        }
        return d[len2-1];
    }
};