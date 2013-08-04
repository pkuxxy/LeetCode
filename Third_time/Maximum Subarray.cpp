class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        int maxs = A[0];
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            maxs = max(maxs, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxs;
    }
};