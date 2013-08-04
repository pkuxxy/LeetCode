import java.util.HashMap;

class Solution {
	static HashMap<Character, Integer> map = new HashMap<Character, Integer>();
	static 
	{
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
	}
    public int romanToInt(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.length() == 1)
        	return map.get(s.charAt(0));

        int sum = 0;
        int first = map.get(s.charAt(0));
        int second = 0;
        for(int i = 0; i < s.length()-1; i++)
        {
        	second = map.get(s.charAt(i+1));
        	if(first >= second)
        	{
        		sum += first;
        	}
        	else
        	{
        		sum -= first;
        	}
        	first = second;
        }
        sum += first;
        return sum;
    }
}
public class RomanToInteger {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution sol = new Solution();
		System.out.println(sol.romanToInt("MMCDXVIII"));
	}

}
