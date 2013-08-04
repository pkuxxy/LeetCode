class Solution {
    public boolean isScramble(String s1, String s2) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(s1.equals(s2))
    		return true;
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
        	return false;
        else if(len1 == 0 || len2 == 0)
        	return false;
        for(int i = 1; i <= len1/2; i++)
        {
        	String a1 = s1.substring(0,i);
        	String b1 = s1.substring(i);
        	String a2 = s2.substring(0,i);
        	String b2 = s2.substring(i);
        	String c1 = s1.substring(0,len1-i);
        	String d1 = s1.substring(len1-i);
        	String c2 = s2.substring(0,len1-i);
        	String d2 = s2.substring(len1-i);
        	if(isScramble(a1, a2) && isScramble(b1, b2))
        		return true;
        	if(isScramble(a1, d2) && isScramble(b1, c2))
        		return true;
        	if(isScramble(d1, a2) && isScramble(c1, b2))
        		return true;
        	if(isScramble(d1, d2) && isScramble(c1, c2))
        		return true;
        }
        return false;
    }
}
public class ScrambleString {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
