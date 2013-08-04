class Solution {
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		// Start typing your Java solution below
		// DO NOT write main() function
		int len1 = obstacleGrid.length;
		int len2 = obstacleGrid[0].length;
		int[][] sum = new int[len1][len2];
		int init = 1;
		for (int i = 0; i < len1; i++) {
			if (obstacleGrid[i][0] == 1)
				init = 0;
			sum[i][0] = init;
		}
		init = 1;
		for (int i = 0; i < len2; i++) {
			if (obstacleGrid[0][i] == 1)
				init = 0;
			sum[0][i] = init;
		}
		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (obstacleGrid[i][j] == 1)
					sum[i][j] = 0;
				else
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1];
			}
		}
		return sum[len1 - 1][len2 - 1];
	}
}

public class UniquePathsII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
