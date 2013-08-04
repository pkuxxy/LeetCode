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
	int sum;
	public int sumNumbers(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		sum = 0;
		ArrayList<Integer> path = new ArrayList<Integer>();
		dfs(root, path);
		return sum;
	}
	private void dfs(TreeNode root, ArrayList<Integer> path) {
		if(root == null)
			return;
		path.add(root.val);
		if(isLeaf(root))
		{
			sum += arrayToInt(path);
		}
		else
		{
			dfs(root.left, path);
			dfs(root.right, path);
		}
		path.remove(path.size()-1);
		
	}
	private int arrayToInt(ArrayList<Integer> path) {
		int sum = 0;
		for(int i = 0; i < path.size(); i++)
		{
			sum *= 10;
			sum += path.get(i);
		}
		return sum;
	}
	private boolean isLeaf(TreeNode root) {
		if(root == null)
			return false;
		if(root.left == null && root.right == null)
			return true;
		return false;
	}
}

public class SumRoottoLeafNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
