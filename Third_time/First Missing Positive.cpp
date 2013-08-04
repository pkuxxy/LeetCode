class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 1;
        for(int i = 0; i < n; i++)
        {
            if(A[i] >= 0 && A[i] < n && A[i] != i && A[i] != A[A[i]])
            {
                swap(A[i], A[A[i]]);
                i--;
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(A[i] != i)
                return i;
        }
        return A[0] == n?n+1:n;
    }
};