import java.util.ArrayList;

class Solution {
	ArrayList<Integer> ret = new ArrayList<Integer>();

	public ArrayList<Integer> spiralOrder(int[][] matrix) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		if (matrix == null || matrix.length == 0)
			return ret;
		int m = matrix.length;
		int n = matrix[0].length;

		int level = 0;
		for (; level < m / 2 && level < n / 2; level++) {
			for (int i = level; i < n - level; i++) {
				ret.add(matrix[level][i]);
			}
			for (int i = level + 1; i < m - level; i++) {
				ret.add(matrix[i][n - level - 1]);
			}
			for (int i = n - level - 2; i >= level; i--) {
				ret.add(matrix[m - level - 1][i]);
			}
			for (int i = m - level - 2; i >= level + 1; i--) {
				ret.add(matrix[i][level]);
			}
		}
		if (m % 2 == 1 || n % 2 == 1) {
			for (int i = level; i < m - level; i++) {
				for(int j = level; j < n - level; j++)
				ret.add(matrix[i][j]);
			}
		}
		return ret;
	}
}

public class SpiralMatrix {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int[][] matrix = { { 2, 3, 4 }, { 5, 6, 7 }, { 8, 9, 10 },
				{ 11, 12, 13 } };
		Solution sol = new Solution();
		System.out.println(sol.spiralOrder(matrix));
	}

}
