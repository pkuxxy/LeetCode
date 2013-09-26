class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = 0;
        int k = n-1;
        while(i<n && A[i] == 0)
            i++;
        while(k >= 0 && A[k] == 2)
            k--;
        j = i;
        while(j <= k)
        {
            if(A[j] == 0)
            {
                swap(A[i],A[j]);
                i++;
                j = max(j, i);
            }
            else if(A[j] == 2)
            {
                swap(A[j], A[k]);
                k--;
            }
            else
                j++;
        }
    }
};