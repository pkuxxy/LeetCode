class Solution {
    public boolean isPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null)
        	return false;
        s = s.trim().toLowerCase();
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
        	while(i < j && !isAlpha(s.charAt(i)))
        	{
        		i++;
        	}
        	while(i < j && !isAlpha(s.charAt(j)))
        	{
        		j--;
        	}
        	if(i < j && s.charAt(i) != s.charAt(j))
        		return false;
        	i++;
        	j--;
        }
        return true;
    }

	private boolean isAlpha(char ch) {
		// TODO Auto-generated method stub
		if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
			return true;
		return false;
	}
}
public class ValidPalindrome {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = ".,";
		Solution sol = new Solution();
		System.out.println(sol.isPalindrome(s));
	}

}
