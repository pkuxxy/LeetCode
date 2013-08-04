import java.util.ArrayList;
import java.util.HashMap;

class Solution {
	static HashMap<Character, String> map = new HashMap<Character, String>();
	static{
		map.put('2', "abc");
		map.put('3', "def");
		map.put('4', "ghi");
		map.put('5', "jkl");
		map.put('6', "mno");
		map.put('7', "pqrs");
		map.put('8', "tuv");
		map.put('9', "wxyz");
	}
	ArrayList<String> ret = new ArrayList<String>();
    public ArrayList<String> letterCombinations(String digits) {
    	ret.clear();
        if(digits == null || digits.length() == 0)
        {
        	ret.add("");
        	return ret;
        }
        StringBuilder sb = new StringBuilder();
        dfs(digits, 0, sb);
        return ret;
    }
	private void dfs(String digits, int start, StringBuilder sb) {
		if(start >= digits.length())
		{
			ret.add(new String(sb.toString()));
			return;
		}
		String cur = map.get(digits.charAt(start));
		{
			for(int i = 0; i < cur.length(); i++)
			{
				sb.append(cur.charAt(i));
				dfs(digits, start+1, sb);
				sb.deleteCharAt(sb.length()-1);
			}
		}
	}
}
public class LetterCombinationsofaPhoneNumber {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
