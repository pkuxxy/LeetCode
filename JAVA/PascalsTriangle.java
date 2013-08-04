import java.util.ArrayList;

class Solution {
	public ArrayList<ArrayList<Integer>> generate(int numRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    	for(int i = 0; i < numRows; i++)
    	{
    		ArrayList<Integer> list = new ArrayList<Integer>();
    		list.add(1);
    		if(i != 0)
    		{
    			ArrayList<Integer> pre = ret.get(i-1);
    			for(int j = 1; j < i; j++)
    			{
    				list.add(pre.get(j)+pre.get(j-1));
    			}
    			list.add(1);
    		}
    		ret.add(list);
    	}
    	return ret;
    }
}

public class PascalsTriangle {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
