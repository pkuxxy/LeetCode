class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
            return true;
        int step = 1;
        for(int i = 0; i < n; i++)
        {
            step--;
            step = max(step, A[i]);
            if(!step && i != n-1)
                return false;
        }
        return true;
    }
};