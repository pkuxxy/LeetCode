class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = matrix.size();
        if(!len1)
            return false;
        int len2 = matrix[0].size();
        int l = 0;
        int r = len1-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
            {
                l = mid+1;
            }
            else
                r = mid-1;
        }
        if(r < 0)
            return false;
        int row = r;
        l = 0;
        r = len2-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};