class Solution {
    public String countAndSay(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(n < 1)
    		return null;
        String str = "1";
        while(--n > 0)
        {
        	StringBuilder sb = new StringBuilder();
        	int count = 1;
        	int i = 1;
        	for(; i < str.length(); i++)
        	{
        		if(str.charAt(i) == str.charAt(i - 1))
        		{
        			count++;
        			continue;
        		}
        		sb.append(String.valueOf(count)).append(str.charAt(i-1));
        		count = 1;
        	}
        	sb.append(String.valueOf(count)).append(str.charAt(i-1));
        	str = sb.toString();
        }
        return str;
    }
}
public class CountandSay {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
