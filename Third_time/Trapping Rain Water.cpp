class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int maxh = 0;
        for(int i = 0; i < n; i++)
        {
            left[i] = maxh;
            maxh = max(maxh, A[i]);
        }
        maxh = 0;
        for(int i = n-1; i >= 0; i--)
        {
            right[i] = maxh;
            maxh = max(maxh, A[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += max(0, min(left[i], right[i])-A[i]);
        }
        return sum;
    }
};