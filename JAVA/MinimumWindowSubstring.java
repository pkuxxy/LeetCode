class Solution {
    public String minWindow(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] count1 = new int[256];
        int[] count2 = new int[256];
        for(int i = 0; i < T.length(); i++)
        {
        	count1[T.charAt(i)]++;
        	count2[T.charAt(i)]++;
        }
        int start = 0;
        int minSize = Integer.MAX_VALUE;
        int minStart = start;
        int end = 0;
        int count = T.length();
        for(; end < S.length(); end++)
        {
        	if(count2[S.charAt(end)] > 0)
        	{
        		count1[S.charAt(end)]--;
        		if(count1[S.charAt(end)] >= 0)
        			count--;
        	}
        	else
        		continue;
        	if(count == 0)
        	{
        		while(true)
        		{
        			if(count2[S.charAt(start)] > 0)
        			{
        				if(count1[S.charAt(start)] < 0)
        					count1[S.charAt(start)]++;
        				else
        					break;
        			}
        			start++;
        		}
        		int size = end - start + 1;
        		if(minSize > size)
        		{
        			minSize = size;
        			minStart = start;
        		}
        	}
        }
        if(minSize == Integer.MAX_VALUE)
        	return "";
        return S.substring(minStart, minStart+minSize);
    }
}
public class MinimumWindowSubstring {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String S = "a";
		String T = "a";
		Solution sol = new Solution();
		System.out.println(sol.minWindow(S, T));
	}

}
