class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || n <= 0)
            return 0;
        int tail = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[tail] != A[i])
                A[++tail] = A[i];
        }
        return tail+1;
    }
};