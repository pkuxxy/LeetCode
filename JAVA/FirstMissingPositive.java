class Solution {
    public int firstMissingPositive(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A == null || A.length == 0)
        	return 1;
        int i = 0;
        int len = A.length;
        while(i < len)
        {
        	if(A[i] == i)
        		i++;
        	else
        	{
        		if(A[i] >= 0 && A[i] < len && A[A[i]] != A[i])
        		{
        			int t = A[A[i]];
        			A[A[i]] = A[i];
        			A[i] = t;
        			continue;
        		}
        		else
        			i++;
        		
        	}
        }
        for(i = 1; i < len; i++)
        {
        	if(A[i] != i)
        		return i;
        }
        return A[0] == len ? len+1 : len;
    }
}
public class FirstMissingPositive {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
