class Solution {
    public int numTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] dp = new int[n+1];
        for(int i = 0; i <=n ;i++)
        	dp[i] = 0;
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <=n ;i++)
        {
        	for(int j = 1; j <=i; j++)
        		dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }
}
public class UniqueBinarySearchTrees {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
