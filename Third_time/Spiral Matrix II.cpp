class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return vector<vector<int>>();
        vector<vector<int>> ret(n, vector<int>(n));
        int count = 1;
        for(int i = 0; i <= n/2; i++)
        {
            for(int j = i; j < n-i; j++)
                ret[i][j] = count++;
            for(int j = i+1; j < n-i; j++)
                ret[j][n-1-i] = count++;
            for(int j = n-i-2; j >= i; j--)
                ret[n-1-i][j] = count++;
            for(int j = n-i-2; j > i; j--)
                ret[j][i] = count++;
        }
        return ret;
    }
};