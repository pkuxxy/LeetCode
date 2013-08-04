class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        int tail = 0;
        int i = 1;
        for(; i < n; i++)
        {
            if(A[i] != A[tail])
            {
                A[++tail] = A[i];
            }
        }
        return tail+1;
    }
};