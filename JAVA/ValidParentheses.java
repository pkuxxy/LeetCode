import java.util.HashMap;
import java.util.Stack;

class Pair
{
	public int pos;
	public char[] chs;
	public Pair(int p, char[] cs)
	{
		pos = p;
		chs = cs;
	}
}
class Solution {
	static HashMap<Character, Pair> map = new HashMap<Character, Pair>();
	static
	{
		char[] p1 = {'(',')'};
		char[] p2 = {'[',']'};
		char[] p3 = {'{','}'};
		map.put('(', new Pair(0, p1));
		map.put(')', new Pair(1, p1));
		map.put('[', new Pair(0, p2));
		map.put(']', new Pair(1, p2));
		map.put('{', new Pair(0, p3));
		map.put('}', new Pair(1, p3));
	}
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s == null)
        	return true;
        int len = s.length();
        if(len % 2 == 1)
        	return false;
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0; i < len; i++)
        {
        	char ch = s.charAt(i);
        	Pair pair = map.get(ch);
        	if(pair.pos == 0)
        	{
        		stack.push(ch);
        	}
        	else
        	{
        		if(stack.isEmpty())
        			return false;
        		char top = stack.pop();
        		if(top != pair.chs[0])
        			return false;
        	}
        }
        if(stack.isEmpty())
        	return true;
        return false;
        
    }
}
public class ValidParentheses {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
