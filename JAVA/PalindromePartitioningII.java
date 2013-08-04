class Solution {
    public int minCut(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null || s.length() <= 1)
        	return 0;
        int len = s.length();
        boolean[][] b = new boolean[len][len];
        for(int i = 0; i < len; i++)
        {
        	b[i][i] = true;
        }
        for(int i = 0; i < len-1; i++)
        {
        	if(s.charAt(i) == s.charAt(i+1))
        		b[i][i+1] = true;
        }
        for(int l = 3; l <= len; l++)
        {
        	for(int i = 0; i <= len - l; i++)
        	{
        		int j = i + l -1;
        		if(s.charAt(i) == s.charAt(j) && b[i+1][j-1])
        			b[i][j] = true;
        	}
        }
        int[] d = new int[len];
        for(int i = 0; i < len ;i++)
        {
        	if(b[0][i])
        	{
        		d[i] = 0;
        		continue;
        	}
        	d[i] = Integer.MAX_VALUE;
        	for(int j = 0; j < i; j++)
        	{
        		if(b[j+1][i])
        			d[i] = Math.min(d[i], d[j]+1);
        	}
        }
        return d[len-1];
    }
}
public class PalindromePartitioningII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
