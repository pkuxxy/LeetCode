class Solution {
    public int jump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A == null || A.length == 0)
        	return 0;
        int maxPos = 0;
        int len = A.length;
        int[] step = new int[len];
        int pos = 0;
        step[0] = 0;
        for(int i = 0; i < len; i++)
        {
        	pos = i + A[i];
        	if(pos >= len)
        		pos = len-1;
        	if(pos > maxPos)
        	{
        		for(int j = maxPos+1; j <= pos; j++)
        		{
        			step[j] = step[i] + 1;
        		}
        		maxPos = pos;
        	}
        	if(maxPos == len-1)
        		return step[len-1];
        }
        return 0;
    }
}
public class JumpGameII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
