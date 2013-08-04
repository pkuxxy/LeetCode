class Solution {
    public int minPathSum(int[][] grid) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len1 = grid.length;
        int len2 = grid[0].length;
        int[][] sum = new int[len1][len2];
        for(int i = 0; i < len1; i++)
        {
        	if(i == 0)
        		sum[i][0] = grid[i][0];
        	else
        		sum[i][0] = sum[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < len2; i++)
        {
        	sum[0][i] = sum[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < len1; i++)
        {
        	for(int j = 1; j < len2; j++)
        	{
        		sum[i][j] = Math.min(sum[i][j-1], sum[i-1][j]) + grid[i][j];
        	}
        }
        return sum[len1-1][len2-1];
    }
}
public class MinimumPathSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
