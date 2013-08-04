class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len1 = matrix.length;
        int len2 = matrix[0].length;
        int i = 0; 
        int j = len2-1;
        while(i < len1 && j >=0)
        {
        	if(matrix[i][j] == target)
        		return true;
        	if(matrix[i][j] < target)
        		i++;
        	else
        		j--;
        }
        return false;
    }
}
public class Searcha2DMatrix {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
