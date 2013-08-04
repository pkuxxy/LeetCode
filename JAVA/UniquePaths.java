class Solution {
    public int uniquePaths(int m, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(m <= 1 || n <= 1)
    		return 1;
        int[][] sum = new int[m][n];
        for(int i = 0; i < m; i++)
        {
        	sum[i][0] = 1;
        }
        for(int i = 0; i < n; i++)
        {
        	sum[0][i] = 1;
        }
        for(int i = 1; i < m; i++)
        {
        	for(int j = 1; j < n; j++)
        	{
        		sum[i][j] = sum[i-1][j] + sum[i][j-1];
        	}
        }
        return sum[m-1][n-1];
    }
}
public class UniquePaths {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}