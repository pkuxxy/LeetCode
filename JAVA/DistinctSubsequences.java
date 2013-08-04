class Solution {
    public int numDistinct(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(S == null || T == null || S.length() == 0)
        	return 0;
        int lens = S.length();
        int lent = T.length();
        int[][] d = new int[lens][lent];
        if(S.charAt(0) == T.charAt(0))
        	d[0][0] = 1;
        else
        	d[0][0] = 0;
        for(int i = 1; i < S.length(); i++)
        {
        	if(S.charAt(i) == T.charAt(0))
        		d[i][0] = d[i-1][0]+1;
        	else
        		d[i][0] = d[i-1][0];
        }
        for(int i = 1; i < S.length(); i++)
        {
        	for(int j = 1; j < T.length(); j++)
        	{
        		if(S.charAt(i) == T.charAt(j))
        			d[i][j] = d[i-1][j]+d[i-1][j-1];
        		else
        			d[i][j] = d[i-1][j];
        	}
        }
        return d[lens-1][lent-1];
    }
}
public class DistinctSubsequences {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
