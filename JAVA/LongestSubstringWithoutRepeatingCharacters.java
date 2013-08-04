import java.util.HashMap;

class Solution {
	
	HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null || s.length() == 0)
        	return 0;
        int start = 0;
        int max = 0;
        StringBuilder sb = new StringBuilder();
        map.clear();
        sb.append(s.charAt(0));
        map.put(s.charAt(0), 0);
        int i = 1;
        for(; i < s.length(); i++)
        {
        	char ch = s.charAt(i);
        	if(map.containsKey(ch))
        	{
        		int len = i - start;
        		if(max < len)
        			max = len;
        		start = map.get(ch) + 1;
        		map.clear();
        		for(int j = start; j <= i; j++)
        			map.put(s.charAt(j), j);
        	}
        	else
        	{
        		map.put(ch, i);
        	}
        }
        int len = i - start;
        if(max < len)
        	max = len;
        return max;
    }
}
public class LongestSubstringWithoutRepeatingCharacters {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
