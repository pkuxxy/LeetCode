class Solution {
    public String longestPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = s.length();
        for(int size = len; size >= 1; size--)
        {
        	for(int i = 0; i < len-size+1; i++)
        	{
        		String sub = s.substring(i, i+size);
        		if(isPalindromic(sub))
        			return sub;
        	}
        }
        return null;
    }

	private boolean isPalindromic(String s) {
		int i = 0;
		int j = s.length()-1;
		while(i<j)
		{
			if(s.charAt(i) != s.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}
}
public class LongestPalindromicSubstring {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
