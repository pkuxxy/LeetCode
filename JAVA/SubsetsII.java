import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
	boolean[] canUse;
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(num == null)
        	return ret;
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        canUse = new boolean[num.length];
        Arrays.sort(num);
        
        dfs(num, 0, num.length, list);
        return ret;
    }
	private void dfs(int[] num, int start, int len, ArrayList<Integer> list) {
		ret.add(new ArrayList<Integer>(list));
		if(start == len)
		{
			return;
		}
		for(int i = start; i < len ;i++)
		{
			if(i > 0 && num[i] == num[i-1] && canUse[i-1] == true)
				continue;
//			dfs(num, i+1, len, list, false);
			list.add(num[i]);
			canUse[i] = false;
			dfs(num, i+1, len, list);
			list.remove(list.size()-1);
			canUse[i] = true;
			
		}
	}
}
public class SubsetsII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
