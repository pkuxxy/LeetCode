class Solution {
public:
    int bs(int a[], int s, int e, int target)
    {
        if(s > e)
            return -1;
        int mid = (s+e)/2;
        if(a[mid] == target)
            return mid;
        else if(a[mid] < target)
        {
            int pos = bs(a, mid+1, e, target);
            return pos == -1 ? e+1:pos;
        }
        else
        {
            int pos = bs(a, s, mid-1, target);
            return pos == -1 ? s : pos;
        }
    }
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        return bs(A, 0, n-1, target);
    }
};