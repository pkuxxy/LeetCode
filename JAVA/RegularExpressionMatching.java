class Solution {
    public boolean isMatch(String s, String p) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null && p == null)
        	return true;
        else if(s == null || p == null)
        	return false;
        return isMatch(s, 0, p, 0);
    }

	private boolean isMatch(String s, int ss, String p, int ps) {
		if(ps >= p.length())
			return ss >= s.length();
			
		if(ps+1 == p.length())
		{
			if(ss+1 == s.length() && (s.charAt(ss) == p.charAt(ps) || p.charAt(ps) == '.'))
				return true;
			return false;
		}
		if(p.charAt(ps+1) != '*')
		{
			if(ss < s.length() && (s.charAt(ss) == p.charAt(ps) || p.charAt(ps) == '.'))
				return isMatch(s, ss+1, p, ps+1);
			return false;
		}
		else
		{
			while(ss < s.length() && (s.charAt(ss) == p.charAt(ps) || p.charAt(ps) == '.'))
			{
				if(isMatch(s, ss, p, ps+2))
					return true;
				ss++;
			}
			return isMatch(s, ss, p, ps+2);
			
		}
	}
}
public class RegularExpressionMatching {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
