class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m <= 0 || n <= 0)
        return 0;
        vector<int> ret(n,1);
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j > 0)
                    ret[j] += ret[j-1];
            }
        }
        return ret[n-1];
    }
};