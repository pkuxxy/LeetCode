class Solution {
public:
    int len1;
    int len2;
    void dfs(vector<vector<char>> &board, int row, int col)
    {
        if(row < 0 || row >= len1 || col < 0 || col >= len2 || board[row][col] != 'O')
            return;
        board[row][col] = 'D';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);

    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        len1 = board.size();
        if(!len1)
            return;
        len2 = board[0].size();
        for(int i = 0; i < len1; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, len2-1);
        }
        for(int i = 0; i < len2; i++)
        {
            dfs(board, 0, i);
            dfs(board, len1-1, i);
        }
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};