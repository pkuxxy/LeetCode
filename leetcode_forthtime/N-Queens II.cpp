class Solution {
public:
    int ret;
    bool canplace(vector<int>& pos, int row, int col)
    {
        for(int i = 0; i < row; i++)
        {
            int j = pos[i];
            if(j == col || (i+j) == (row+col) || (i-j) == (row-col))
                return false;
        }
        return true;
    }
    void place(vector<int>& pos, int index, int n)
    {
        if(index == n)
        {
            ret++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(canplace(pos, index, i))
            {
                pos[index] = i;
                place(pos, index+1, n);
            }
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        vector<int> pos(n);
        place(pos, 0, n);
        return ret;
    }
};