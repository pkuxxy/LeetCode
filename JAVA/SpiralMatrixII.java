class Solution {
    public int[][] generateMatrix(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	
        int[][] ret = new int[n][n];
        int num = 1;
        for(int level = 0; level < n/2; level++)
        {
        	for(int i = level; i < n - level; i++)
        	{
        		ret[level][i] = num++;
        	}
        	for(int i = level + 1; i < n - level; i++)
        	{
        		ret[i][n - level - 1] = num++;
        	}
        	for(int i = n - level - 2; i >= level; i--)
        	{
        		ret[n - level - 1][i] = num++;
        	}
        	for(int i = n- level - 2; i >= level+1; i--)
        	{
        		ret[i][level] = num++;
        	}
        }
        if((n % 2) == 1)
        {
        	ret[n/2][n/2] = num;
        }
        return ret;
    }
}
public class SpiralMatrixII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
