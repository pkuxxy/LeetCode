import java.util.HashSet;

class Solution {

	public void solveSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        solve(board, 0, 0, board.length, board[0].length);
    }

	private boolean solve(char[][] board, int i, int j, int len1, int len2) {
		if(i == len1-1 && j == len2)
		{
			return true;
		}
		if(j == len2)
		{
			j = 0;
			i++;
		}
		if(board[i][j] != '.')
			return solve(board, i, j+1, len1, len2);
		else
		{
			for(char ch = '1'; ch <= '9'; ch++)
			{
				board[i][j] = ch;
				if(!isValid(board, i,j))
					continue;
				if(solve(board, i, j+1, len1, len2))
					return true;
			}
			board[i][j] = '.'; 
			return false;
		}
	}

	private boolean isValid(char[][] board, int row, int col) {
		HashSet<Character> set = new HashSet<Character>();
		for(int i = 0; i < 9; i++)
		{
			if(board[row][i] != '.' && set.contains(board[row][i]))
				return false;
			set.add(board[row][i]);
		}
		set.clear();
		for(int i = 0; i < 9; i++)
		{
			if(board[i][col] != '.' && set.contains(board[i][col]))
				return false;
			set.add(board[i][col]);
		}
		set.clear();
		int ltx = (row/3)*3;
		int lty = (col/3)*3;
		for(int i = ltx; i < ltx+3; i++)
		{
			for(int j = lty; j < lty+3; j++)
			{
				if(board[i][j] != '.' && set.contains(board[i][j]))
					return false;
				set.add(board[i][j]);
			}
		}
		return true;
	}
}
public class SudokuSolver {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] strs = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
		char[][] board = new char[9][9];
		for(int i = 0; i < 9; i++)
		{
			board[i] = strs[i].toCharArray();
		}
		Solution sol = new Solution();
		sol.solveSudoku(board);
	}

}
