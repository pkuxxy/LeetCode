class Solution {
    public boolean canJump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length == 1)
        	return true;
        int step = A[0];
        for(int i = 1; i < A.length; i++)
        {
        	if(step > 0)
        	{
        		step--;
        		step = Math.max(step, A[i]);
        	}
        	else
        		return false;
        }
        return true;
    }
}
public class JumpGame {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
