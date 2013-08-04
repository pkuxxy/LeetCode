import java.util.ArrayList;

class Solution {
	ArrayList<String> ret = new ArrayList<String>();
    public ArrayList<String> generateParenthesis(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        dfs(0, 2*n, 0, 0, "");
        return ret;
    }
	private void dfs(int index, int len, int leftNum, int leftTotal, String s) {
		if(leftTotal*2 > len)
			return;
		if(index == len)
		{
			ret.add(s);
			return;
		}
		for(int i = 0; i < 2; i++)
		{
			if(i == 0)
				dfs(index+1, len, leftNum+1, leftTotal+1, s+"(");
			else
			{
				if(leftNum > 0)
					dfs(index+1, len, leftNum-1, leftTotal, s+")");
			}
				
		}
	}
}
public class GenerateParentheses {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 1;
		Solution sol = new Solution();
		System.out.println(sol.generateParenthesis(n));
	}

}
