class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = obstacleGrid.size();
        if(!len1)
            return 0;
        int len2 = obstacleGrid[0].size();
        vector<int> ret(len2,0);
        ret[0] = 1-obstacleGrid[0][0];
        for(int i = 1; i < len2; i++)
        {
            ret[i] = obstacleGrid[0][i]?0:ret[i-1];
        }
        for(int i = 1; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(obstacleGrid[i][j])
                    ret[j] = 0;
                else if(j > 0)
                    ret[j] += ret[j-1];
            }
        }
        return ret[len2-1];
    }
};