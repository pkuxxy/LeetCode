class Solution {
public:
    int len1;
    int len2;
    int len;
    bool dfs(vector<vector<char> > &board, int row, int col, string word, int index, vector<vector<bool>>& canUse)
    {
        if(index == len)
            return true;
        if(row < 0 || row >= len1 || col < 0 || col >= len2 || !canUse[row][col] || board[row][col] != word[index])
            return false;
        canUse[row][col] = false;
        if(dfs(board, row+1, col, word, index+1, canUse))
            return true;
                if(dfs(board, row-1, col, word, index+1, canUse))
            return true;
                if(dfs(board, row, col+1, word, index+1, canUse))
            return true;
                if(dfs(board, row, col-1, word, index+1, canUse))
            return true;
        canUse[row][col] = true;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        len1 = board.size();
        if(!len1)
            return false;
        len = word.size();
        if(!len)
            return false;
        len2 = board[0].size();
        vector<vector<bool>> canUse(len1, vector<bool>(len2, true));
        for(int i = 0; i < len1; i ++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(dfs(board,i,j, word,0,canUse))
                    return true;
            }
        }
        return false;
    }
};