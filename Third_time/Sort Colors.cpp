class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos1 = 0;
        int pos2 = n-1;
        while(pos1 < n && A[pos1] == 0)
            pos1++;
        int cur = pos1;
        while(pos2 >= 0 && A[pos2] == 2)
            pos2--;
        while(pos1 <= cur && cur <= pos2)
        {
            while((pos1 <= cur && cur <= pos2) && (A[cur] == 0 || A[cur] == 2))
            {
                if(A[cur] == 0)
                    swap(A[pos1++], A[cur]);
                else
                    swap(A[pos2--], A[cur]);
            }
            cur++;
        }
    }
};