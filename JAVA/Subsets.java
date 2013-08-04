import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();

	public ArrayList<ArrayList<Integer>> subsets(int[] S) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		ArrayList<Integer> path = new ArrayList<Integer>();
		Arrays.sort(S);
		dfs(S, 0, S.length, path);
		return ret;
	}

	private void dfs(int[] s, int start, int len, ArrayList<Integer> path) {
		if(start == len)
		{
			ret.add(new ArrayList<Integer>(path));
			return;
		}
		dfs(s, start+1, len, path);
		path.add(s[start]);
		dfs(s, start+1, len, path);
		path.remove(path.size()-1);
	}
}

public class Subsets {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
