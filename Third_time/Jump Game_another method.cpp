class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
            return true;
        int step = 0;
        for(int i = 0; i < n-1; i++)
        {
            step = max(step, i+A[i]);
            if(step == i+A[i] && A[i] == 0)
                return false;
        }
        return true;
    }
};