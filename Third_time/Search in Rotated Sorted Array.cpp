class Solution {
public:
    int bs(int a[], int s, int e, int target)
    {
        if(s > e)
            return -1;
        int mid = (s+e)/2;
        if(a[mid] == target)
            return mid;
        else if(a[s] <= a[mid])
        {
            if(a[s] <= target && target <= a[mid])
                return bs(a, s, mid-1, target);
            else
                return bs(a, mid+1, e, target);
        }
        else
        {
            if(a[mid] <= target && target <= a[e])
                return bs(a, mid+1, e, target);
            else
                return bs(a, s, mid-1, target);
        }
    }
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bs(A, 0, n-1, target);
    }
};