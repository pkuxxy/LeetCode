class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || n <= 0)
            return;
        int p0 = 0;
        int p1 = n-1;
        int p2 = n-1;
        int cur = 0;
        while(cur <= p1)
        {
            if(A[cur] == 0)
                cur++;
            else if(A[cur] == 2)
            {
                swap(A[cur], A[p2]);
                p2--;
                if(p1 > p2)
                    p1--;
            }
            else if(A[cur] == 1)
            {
                swap(A[cur], A[p1]);
                p1--;
            }
        }
    }
};