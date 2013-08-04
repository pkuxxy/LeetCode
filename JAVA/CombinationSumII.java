import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        ArrayList<Integer> path = new ArrayList<Integer>();
        Arrays.sort(num);
        solve(num, 0, num.length, target, path);
        return ret;
    }
	private void solve(int[] num, int index, int len, int target,
			ArrayList<Integer> path) {
		if(target == 0)
		{
			ret.add(new ArrayList<Integer>(path));
			return;
		}
		if(target < 0)
			return;
		for(int i = index; i < len; i++)
		{
			if(i > index && num[i] == num[i-1])
				continue;
			path.add(num[i]);
			solve(num, i+1, len, target - num[i], path);
			path.remove(path.size()-1);
		}
		
	}
}
public class CombinationSumII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
