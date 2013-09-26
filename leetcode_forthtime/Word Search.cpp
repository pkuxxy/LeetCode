class Solution {
public:
    bool dfs(vector<vector<char> > &board, int row, int col, string word, int index, vector<vector<bool>>& visited)
    {
        if(index == word.size())
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[index])
            return false;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        visited[row][col] = true;
        for(int i = 0; i < 4; i++)
        {
            if(dfs(board, row+dx[i], col+dy[i], word, index+1, visited))
                return true;
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = board.size();
        int len2 = board[0].size();
        vector<vector<bool>> visited(len1, vector<bool>(len2, false));
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                if(dfs(board, i, j, word, 0, visited))
                    return true;
            }
        }
        return false;
    }
};