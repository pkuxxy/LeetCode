class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        int end = 0;
        int step = 0;
        int count = 0;
        while(step < n-1)
        {
            count++;
            for(int i = start; i <= end; i++)
            {
                step = max(step, i+A[i]);
            }
            if(step <= end)
                return INT_MAX;
            start = end+1;
            end = step;
        }
        return count;
    }
};