class Solution {
    public int trap(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
       
        int len = A.length;
        int[] left = new int[len];
        int[] right = new int[len];
        int maxHeight = 0;
        for(int i = 0; i < len ;i ++)
        {
        	left[i] = maxHeight;
        	maxHeight = Math.max(maxHeight, A[i]);
        }
        maxHeight = 0;
        for(int i = len-1; i >= 0; i--)
        {
        	right[i] = maxHeight;
        	maxHeight = Math.max(maxHeight, A[i]);
        }
        int sum = 0;
        int cur = 0;
        for(int i = 0; i < len; i++)
        {
        	cur = Math.min(left[i], right[i]) - A[i];
        	if(cur < 0)
        		continue;
        	sum += cur;
        }
        return sum;
    }
}
public class TrappingRainWater {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {0,2,0};
		Solution sol = new Solution();
		sol.trap(a);
	}

}
