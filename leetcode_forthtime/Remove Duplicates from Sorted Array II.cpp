class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || n <= 0)
            return 0;
        int count = 1;
        int tail = 1;
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[i-1])
                count++;
            else
                count = 1;
            if(count <= 2)
                A[tail++] = A[i];
        }
        return tail;
    }
};