class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tail = m + n -1;
        m--;
        n--;
        while(tail >= 0)
        {
            if(m < 0)
                A[tail--] = B[n--];
            else if(n < 0)
                A[tail--] = A[m--];
            else
                A[tail--] = A[m] > B[n] ? A[m--] : B[n--];
        }
    }
};