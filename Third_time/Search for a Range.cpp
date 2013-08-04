class Solution {
public:
    int bs(int a[], int s, int e, int target, bool left)
    {
        if(s > e)
            return -1;
        int mid = (s+e)/2;
        if(a[mid] == target)
        {
            int pos = left?bs(a, s, mid-1, target, left):bs(a, mid+1, e, target, left);
            return pos == -1 ? mid:pos;
        }
        else if(a[mid] < target)
        {
            return bs(a, mid+1, e, target, left);
        }
        else
            return bs(a, s, mid-1, target, left);
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int left = bs(A, 0, n-1, target,true);
        int right = bs(A, 0, n-1, target, false);
        ret.push_back(left);
        ret.push_back(right);
        return ret;
    }
};