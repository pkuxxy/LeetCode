class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	int len1 = s1.length();
    	int len2 = s2.length();
    	int len3 = s3.length();
    	if(len1 + len2 != len3)
    		return false;
    	boolean[][] m = new boolean[len1+1][len2+1];
    	m[0][0] = true;
    	for(int i = 1; i <= len1; i++)
    	{
    		m[i][0] = m[i-1][0] && s1.charAt(i-1) == s3.charAt(i-1);
    	}
    	for(int i = 1; i <= len2; i++)
    	{
    		m[0][i] = m[0][i-1] && s2.charAt(i-1) == s3.charAt(i-1);
    	}
    	for(int i = 1; i <= len1; i++)
    	{
    		for(int j = 1; j <= len2; j++)
    		{
    			m[i][j] = (m[i-1][j] && s1.charAt(i-1) == s3.charAt(i-1+j)) || (m[i][j-1] && s2.charAt(j-1) == s3.charAt(i+j-1));
    		}
    	}
    	return m[len1][len2];
    }
}
public class InterleavingString_iterative {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
