class Solution {
    public void rotate(int[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(matrix == null || matrix.length == 0)
        	return;
        int len = matrix.length;

        for(int level = 0; level < len/2; level++)
        {
        	for(int i = level; i < len - level - 1; i++)
        	{
        		int temp = matrix[level][i];
        		matrix[level][i] = matrix[len-i-1][level];
        		matrix[len-i-1][level] = matrix[len-level-1][len-i-1];
        		matrix[len-level-1][len-i-1] = matrix[i][len-level-1];
        		matrix[i][len-level-1] = temp;
        	}
        }
    }
}
public class RotateImage {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
