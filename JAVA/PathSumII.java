import java.util.ArrayList;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
	public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		ArrayList<Integer> path = new ArrayList<Integer>();
		dfs(root, sum, path);
		return ret;
	}
	private void dfs(TreeNode root, int sum, ArrayList<Integer> path) {
		if(root == null)
			return;
		path.add(root.val);
		if(isLeaf(root))
		{
			if(sum == root.val)
			{
				ret.add((ArrayList<Integer>) path.clone());
			}
		}
		else
		{
			dfs(root.left, sum-root.val, path);
			dfs(root.right, sum-root.val, path);
		}
		path.remove(path.size()-1);
		
	}
	private boolean isLeaf(TreeNode root) {
		if(root == null)
			return false;
		if(root.left == null && root.right == null)
			return true;
		return false;
	}
}

public class PathSumII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
