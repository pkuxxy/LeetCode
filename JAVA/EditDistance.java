class Solution {
    public int minDistance(String word1, String word2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] f = new int[len1+1][len2+1];
        for(int i = 0; i <= len1; i++)
        {
        	f[i][0] = i;
        }
        for(int i = 0; i <= len2; i++)
        {
        	f[0][i] = i;
        }
        for(int i = 1; i <= len1; i++)
        {
        	for(int j = 1; j <= len2; j++)
        	{
        		f[i][j] = Integer.MAX_VALUE;
        		if(word1.charAt(i-1) == word2.charAt(j-1))
        			f[i][j] = f[i-1][j-1];
        		f[i][j] = Math.min(f[i][j], f[i-1][j-1]+1);
        		f[i][j] = Math.min(f[i][j], Math.min(f[i-1][j], f[i][j-1])+1);
        	}
        }
        return f[len1][len2];
    }
}
public class EditDistance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
