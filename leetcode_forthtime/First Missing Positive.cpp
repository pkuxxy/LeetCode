class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 1;
        while(i < n)
        {
            if(A[i] != i && A[i] >= 0 && A[i] < n && A[i] != A[A[i]])
                swap(A[i], A[A[i]]);
            else
                i++;
        }
        i = 1;
        for(; i < n; i++)
        {
            if(A[i] != i)
                return i;
        }
        return A[0] == n?n+1:n;
    }
};