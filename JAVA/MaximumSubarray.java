class Solution {
    public int maxSubArray(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	int sum = 0;
    	int max = Integer.MIN_VALUE;
    	for(int i = 0; i < A.length; i++)
    	{
    		if(A[i] < 0)
    		{
    			if(sum + A[i] < 0)
    				sum = A[i];
    			else
    				sum += A[i];
    		}
    		else
    		{
    			if(sum < 0)
    				sum = A[i];
    			else
    				sum += A[i];
    		}
    			
    		if(max < sum)
    			max = sum;
    	}
    	return max;
    }
}
public class MaximumSubarray {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
