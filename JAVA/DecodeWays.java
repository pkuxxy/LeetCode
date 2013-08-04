class Solution {
    public int numDecodings(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null || s.length() == 0)
        	return 0;
        int len = s.length();
        int[] ways = new int[len+1];
        ways[0] = 1;
        if(s.charAt(0) == '0')
        	ways[1] = 0;
        else
        	ways[1] = 1;
        int pre = s.charAt(0)-'0';
        for(int i = 1; i < len; i++)
        {
        	int cur = s.charAt(i)-'0';
        	if(pre == 0 && cur == 0)
        		return 0;
        	if(cur > 6)
        	{
        		if(pre >= 2 || pre == 0)
        			ways[i+1] = ways[i];
        		else
        			ways[i+1] = ways[i] + ways[i-1];
        	}
        	else if(cur >= 1)
        	{
        		if(pre >= 3 || pre == 0)
        			ways[i+1] = ways[i];
        		else 
        			ways[i+1] = ways[i] + ways[i-1];
        	}
        	else
        	{
        		if(pre >= 3)
        			return 0;
        		else
        			ways[i+1] = ways[i-1];
        	}
        	pre = cur;
        }
        return ways[len];
    }
}
public class DecodeWays {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
