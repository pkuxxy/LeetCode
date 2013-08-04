import java.util.ArrayList;

class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> ret = new ArrayList<Integer>();
        ret.add(1);
        ArrayList<Integer> pre = new ArrayList<Integer>(ret);
        for(int i = 1; i <= rowIndex; i++)
        {
        	ret.clear();
        	ret.add(1);
        	for(int j = 1; j < pre.size(); j++)
        	{
        		ret.add(pre.get(j) + pre.get(j-1));
        	}
        	ret.add(1);
        	pre = new ArrayList<Integer>(ret);
        }
        return ret;
    }
}
public class PascalsTriangleII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
