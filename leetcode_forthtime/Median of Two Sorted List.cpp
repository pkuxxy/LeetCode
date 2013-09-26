class Solution {
public:
    double medianOfThree(int a, int b, int c)
    {
        int sum = a+b+c;
        return sum - min(a, min(b, c)) - max(a, max(b, c));
    }
    double medianOfFour(int a, int b, int c, int d)
    {
        return (a+b+c+d-min(a, min(b, min(c, d))) - max(a, max(b, max(c,d))))/2.0;
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m > n)
            return findMedianSortedArrays(B, n, A, m);
        if(m == 0)
        {
            if(n%2)
                return B[n/2];
            else
                return (B[n/2-1] + B[n/2])/2.0;
        }
        if(m == 1)
        {
            if(n == 1)
                return (A[0]+B[0])/2.0;
            if(n%2)
                return (B[n/2]+medianOfThree(A[0],B[n/2-1],B[n/2+1]))/2.0;
            else
                return medianOfThree(A[0],B[n/2-1],B[n/2]);
        }
        if(m == 2)
        {
            if(n == 2)
                return medianOfFour(A[0], B[0], A[1], B[1]);
            if(n%2)
                return medianOfThree(B[n/2], max(A[1], B[n/2-1]), min(A[0], B[n/2+1]));
            else
                return medianOfFour(B[n/2-1], B[n/2], max(A[1], B[n/2-2]), min(A[0], B[n/2+1]));
        }
        int mid1 = m/2;
        int mid2 = n/2;
        if(A[mid1] < B[mid2])
        {
            if(m%2 == 0)
                mid1--;
            int remove = min(mid1, n-mid2-1);
            return findMedianSortedArrays(A+remove, m-remove, B, n-remove);
        }
        else
        {
            if(n%2 == 0)
                mid2--;
            int remove = min(mid2, m-mid1-1);
            return findMedianSortedArrays(A, m-remove, B+remove, n-remove);
        }
    }
};