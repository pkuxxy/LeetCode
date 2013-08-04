class Solution {
    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
//        if(s == null && p == null)
//        	return true;
//        if(s == null || p == null)
//        	return false;
        if(p.length() == 0)
        	return s.length() == 0;
        else if(s.length() == 0)
        {
        	int i = 0;
        	while(i < p.length() && p.charAt(i) == '*')
        		i++;
        	return i == p.length();
        }
        if(p.charAt(0) != '*')
        {
        	if(p.charAt(0) == s.charAt(0) || p.charAt(0) == '?')
        		return isMatch(s.substring(1), p.substring(1));
        	return false;
        }
        else
        {
        	int i = 0;
        	int notStar = 0;
        	while(notStar < p.length() && p.charAt(notStar) == '*')
        		notStar++;
        	while(i <= s.length())
        	{
        		if(isMatch(s.substring(i), p.substring(notStar)))
        			return true;
        		i++;
        	}
        	return false;
        }
    }
}
public class WildcardMatching_recursive {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
