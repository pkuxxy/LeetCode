import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(board == null || board.length != 9 || board[0].length != 9)
        	return false;
        Set<Integer> set = new HashSet<Integer>();

        for(int i = 0; i < 9; i++)
        {
        	set.clear();
        	for(int j = 0; j < 9; j++)
        	{
        		if(board[i][j] == '.')
        			continue;
        		else if(set.contains(board[i][j] - '0'))
        			return false;
        		set.add(board[i][j] - '0');
        	}
        	set.clear();
        	for(int j = 0; j < 9; j++)
        	{
        		if(board[j][i] == '.')
        			continue;
        		else if(set.contains(board[j][i] - '0'))
        			return false;
        		set.add(board[j][i] - '0');
        	}
        	set.clear();
        	int row = (i/3)*3;
        	int col = (i%3)*3;
        	for(int k = row; k < row + 3; k++)
        	{
        		for(int m = col; m < col + 3; m++)
        		{
            		if(board[k][m] == '.')
            			continue;
            		else if(set.contains(board[k][m] - '0'))
            			return false;
            		set.add(board[k][m] - '0');
        		}
        	}
        }
    	return true;
    }
}
public class ValidSudoku {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
