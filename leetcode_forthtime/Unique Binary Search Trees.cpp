class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        vector<int> d(n+1, 0);
        d[0] = 1;
        d[1] = 1;
        for(int i = 2; i <=n ;i++)
        {
            for(int j = 0; j <i; j++)
            {
                d[i] += d[j]*d[i-j-1];
            }
        }
        return d[n];
    }
};