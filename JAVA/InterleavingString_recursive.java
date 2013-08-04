class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // Start typing your Java solution below
        // DO NOT write main() function
//        if(s1 == null || s2 == null || s3 == null)
//        	return false;
        if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
        	return true;
//        if(s1.equals("") || s2.equals("") || s3.equals(""))
//        	return false;
        if(s3.length() == 0)
        	return false;
        char ch = s3.charAt(0);
        if(s1.length() == 0)
        {
        	if(s2.length() == 0)
        		return false;
        	if(s2.charAt(0) == ch)
        		return isInterleave(s1, s2.substring(1), s3.substring(1));
        	else
        		return false;
        }
        else
        {
        	if(s1.charAt(0) == ch)
        	{
        		boolean tag = isInterleave(s1.substring(1), s2, s3.substring(1));
        		if(tag)
        			return true;
        	}
        	if(s2.length() != 0)
        	{
        		if(s2.charAt(0) == ch)
        			return isInterleave(s1, s2.substring(1), s3.substring(1));
        	}
        	return false;
        }
    }
}
public class InterleavingString_recursive {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
