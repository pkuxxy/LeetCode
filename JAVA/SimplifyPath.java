import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        // Start typing your Java solution below
        // DO NOT write main() function
        String[] tokens = path.split("/");
        Stack<String> stack = new Stack<String>();
        for(int i = 0; i < tokens.length; i++)
        {
        	String str = tokens[i];
        	if(str.equals("") || str.equals("."))
        		continue;
        	if(str.equals(".."))
        	{
        		if(stack.isEmpty())
        			continue;
        		else
        			stack.pop();
        	}
        	else
        		stack.push(str);
        }
        StringBuilder ret = new StringBuilder();
        ret.append("/");
        while(stack.size() > 1)
        {
        	ret.append(stack.get(0)).append('/');
        	stack.remove(0);
        }
        if(stack.size() == 1)
        	ret.append(stack.firstElement());
        return ret.toString();
    }
}
public class SimplifyPath {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String path = "//home/";
		String[] tokens = path.split("/");
	}

}
