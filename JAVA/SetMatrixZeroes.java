class Solution {
	public void setZeroes(int[][] matrix) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if (matrix == null || matrix.length == 0)
			return;
		boolean rowTag = false;
		boolean colTag = false;
		int len1 = matrix.length;
		int len2 = matrix[0].length;
		for (int i = 0; i < len1; i++) {
			if (matrix[i][0] == 0)
				colTag = true;
		}
		for (int i = 0; i < len2; i++) {
			if (matrix[0][i] == 0)
				rowTag = true;
		}
		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if(colTag)
		{
			for(int i = 0; i < len1; i++)
				matrix[i][0] = 0;
		}
		if(rowTag)
		{
			for(int i = 0; i < len2; i++)
				matrix[0][i] = 0;
		}

	}
}

public class SetMatrixZeroes {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] matrix = { { 0, 1 } };
		Solution sol = new Solution();
		sol.setZeroes(matrix);
		System.out.println(matrix);
	}

}
