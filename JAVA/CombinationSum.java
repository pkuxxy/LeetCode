import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
	int[] count;
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(candidates == null || candidates.length == 0)
        	return ret;
        Arrays.sort(candidates);
        count = new int[candidates.length];
        dfs(0, candidates, target);
        return ret;
    }
	private void dfs(int index, int[] candidates, int target) {
		// TODO Auto-generated method stub
		if(target < 0)
			return;
		if(index == candidates.length)
		{
			if(target == 0)
			{
				ArrayList<Integer> cur = new ArrayList<Integer>();
				for(int i = 0; i < index; i++)
				{
					for(int j = 0; j < count[i]; j++)
						cur.add(candidates[i]);
				}
				ret.add(cur);
			}
			return;
		}
		for(int i = 0; i <= target/candidates[index]; i++)
		{
			count[index] = i;
			dfs(index+1, candidates, target-i*candidates[index]);
		}
	}
}
public class CombinationSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] cand = {2};
		int target = 1;
		Solution sol = new Solution();
		System.out.println(sol.combinationSum(cand, target));
	}

}
