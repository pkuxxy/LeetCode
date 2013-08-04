import java.util.Stack;

class Solution {
	static class Node
	{
		public char ch;
		public int index;
		public Node(char c, int i)
		{
			ch = c;
			index = i;
		}
	}
    public int longestValidParentheses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Node> stack = new Stack<Node>();
        stack.push(new Node(')', -1));
        int longest = 0;
        for(int i = 0 ; i < s.length(); i++)
        {
        	char ch = s.charAt(i);
        	if(ch == '(')
        	{
        		stack.push(new Node(ch, i));
        	}
        	else
        	{
        		Node n = stack.peek();
        		if(n.ch == '(')
        		{
        			stack.pop();
        			longest = Math.max(longest, i-stack.peek().index);
        		}
        		else
        			stack.push(new Node(ch, i));
        	}
        }
        return longest;
    }
}
public class LongestValidParentheses {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
