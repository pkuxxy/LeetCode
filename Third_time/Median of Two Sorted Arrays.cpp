class Solution {
public:
    double medianOfThree(int a, int b, int c)
    {
        int minv = min(a, min(b,c));
        int maxv = max(a, max(b,c));
        return (a+b+c-minv-maxv);
    }
    double medianOfFour(int a, int b, int c, int d)
    {
        int minv = min(a, min(b, min(c,d)));
        int maxv = max(a, max(b, max(c,d)));
        return (a+b+c+d-minv-maxv)/2.0;
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
				return (B[n/2]+B[n/2-1])/2.0;
		}
        if(m == 1)
        {
            if(n == 1)
                return (A[0]+B[0])/2.0;
            else if(n%2)
                return (B[n/2]+medianOfThree(B[n/2-1], A[0], B[n/2+1]))/2.0;
            else
                return medianOfThree(A[0],B[n/2], B[n/2-1]);
        }
        if(m == 2)
        {
            if(n == 2)
                return medianOfFour(A[0],A[1], B[0],B[1]);
            else if(n%2)
                return medianOfThree(B[n/2],max(A[1], B[n/2-1]), min(A[0], B[n/2+1]));
            else
                return medianOfFour(B[n/2], B[n/2-1], min(A[0],B[n/2+1]), max(A[1], B[n/2-2]));
        }
        int ida = m/2;
        int idb = n/2;
        int minRemove;
        if(A[ida] < B[idb])
        {
            if(ida%2 == 0)
                ida--;
            minRemove = min(ida, n-idb-1);
            return findMedianSortedArrays(A+minRemove, m-minRemove, B, n-minRemove);
        }
        else
        {
            if(idb%2 == 0)
                idb--;
            minRemove = min(m-ida-1, idb);
            return findMedianSortedArrays(A, m-minRemove, B+minRemove, n-minRemove);
        }
    }
};