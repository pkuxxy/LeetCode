class Solution {
    public int removeDuplicates(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(A == null || A.length == 0)
    		return 0;
    	int start = 0;
    	int end = 1;
    	int count = 1;
    	while(end < A.length)
    	{
    		if(A[start] == A[end])
    		{
    			count++;
    			if(count <= 2)
    			{
    				start++;
    				A[start] = A[end];
    			}
    		}
    		else
    		{
    			count = 1;
    			start++;
    			A[start] = A[end];
    		}
    		end++;
    	}
    	return start+1;
    }
}
public class RemoveDuplicatesfromSortedArrayII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
