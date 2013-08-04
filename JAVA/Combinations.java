import java.util.ArrayList;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        ArrayList<Integer> path = new ArrayList<Integer>();
        dfs(1, 0, n, k, path);
        return ret;
    }
	private void dfs(int start, int nums, int n, int k, ArrayList<Integer> path) {
		if(nums == k)
		{
			ret.add(new ArrayList<Integer>(path));
			return;
		}
		if(start > n)
			return;
		for(int i = start; i <= n; i++)
		{
			path.add(i);
			dfs(i+1, nums+1, n, k, path);
			path.remove(path.size()-1);
		}
	}
    
}
public class Combinations {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution sol = new Solution();
		int n = 2;
		int k = 2;
		System.out.println(sol.combine(n, k));
	}

}
