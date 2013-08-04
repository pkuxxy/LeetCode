import java.awt.Point;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public void solve(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(board == null || board.length <= 2)
        	return;
        int len1 = board.length;
        int len2 = board[0].length;
        if(len2 <= 2)
        	return;
        Queue<Point> q = new LinkedList<Point>();
        for(int i = 0; i < len1; i++)
        {
        	if(board[i][0] == 'O')
        	{
        		board[i][0] = 'D';
        		q.add(new Point(i,0));
        	}
        	if(board[i][len2-1] == 'O')
        	{
        		board[i][len2-1] = 'D';
        		q.add(new Point(i,len2-1));
        	}
        }
        for(int i = 0; i < len2; i++)
        {
        	if(board[0][i] == 'O')
        	{
        		board[0][i] = 'D';
        		q.add(new Point(0,i));
        	}
        	if(board[len1-1][i] == 'O')
        	{
        		board[len1-1][i] = 'D';
        		q.add(new Point(len1-1,i));
        	}
        }
        int[][] path = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.isEmpty())
        {
        	Point pos = q.poll();
        	for(int i = 0; i < path.length; i++)
        	{
        		int x = pos.x + path[i][0];
        		int y = pos.y + path[i][1];
        		if(x < 0 || x >= len1 || y < 0 || y >= len2 || board[x][y] != 'O')
        			continue;
        		board[x][y] = 'D';
        		q.add(new Point(x,y));
        	}
        }
        for(int i = 0; i < len1; i++)
        {
        	for(int j = 0; j < len2; j++)
        	{
        		if(board[i][j] == 'X')
        			continue;
        		board[i][j] = (board[i][j] == 'O' ? 'X' : 'O');
        	}
        }
    }
}
public class SurroundedRegions {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		char[][] board = {{'X','O','X'}, {'O','X','O'},{'X','O','X'}};
		Solution sol = new Solution();
		sol.solve(board);
	}

}
