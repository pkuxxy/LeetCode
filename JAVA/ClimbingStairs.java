class Solution {
    public int climbStairs(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(n < 1)
    		return 0;
        int[] a = new int[n+1];
        a[0] = 1;
        a[1] = 1;
        for(int i = 2; i < a.length; i++)
        {
        	a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
}
public class ClimbingStairs {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
