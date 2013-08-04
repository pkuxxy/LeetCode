import java.util.ArrayList;

class Solution {
	static class Position
	{
		public int x;
		public int y;
		public Position(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
    public boolean exist(char[][] board, String word) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(board == null || word == null)
    		return false;
        int len1 = board.length;
        int len2 = board[0].length;
        boolean[][] visited = new boolean[len1][len2];
        ArrayList<Position> pos = new ArrayList<Position>();
        char first = word.charAt(0);
        for(int i = 0; i < len1; i++)
        {
        	for(int j = 0; j < len2; j++)
        	{
        		visited[i][j] = false;
        		if(first == board[i][j])
        		{
        			pos.add(new Position(i, j));
        		}
        	}
        }
        for(Position p : pos)
        {
        	if(findWord(board, visited, p, 0, word.length(), word))
        		return true;
        }
        return false;
    }
	private boolean findWord(char[][] board, boolean[][] visited, Position p, int index, int len, String word) {
		if(index == len)
			return true;
		if(p.x < 0 || p.x >= board.length || p.y < 0 || p.y >= board[0].length)
			return false;
		if(visited[p.x][p.y])
			return false;
		if(board[p.x][p.y] != word.charAt(index))
			return false;
		
		visited[p.x][p.y] = true;
		if(findWord(board, visited, new Position(p.x-1, p.y), index+1, len, word))
		{
			return true;
		}
		if(findWord(board, visited, new Position(p.x+1, p.y), index+1, len, word))
		{
			return true;
		}
		if(findWord(board, visited, new Position(p.x, p.y-1), index+1, len, word))
		{
			return true;
		}
		if(findWord(board, visited, new Position(p.x, p.y+1), index+1, len, word))
		{
			return true;
		}
		visited[p.x][p.y] = false;
		return false;
	}
}
public class WordSearch {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
