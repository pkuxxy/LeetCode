import java.util.ArrayList;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
		left = null;
		right = null;
	}
}

class Solution {
	public ArrayList<TreeNode> generateTrees(int n) {
		// Start typing your Java solution below
		// DO NOT write main() function
		return generate(1, n);
	}

	private ArrayList<TreeNode> generate(int start, int end) {
		ArrayList<TreeNode> ret = new ArrayList<TreeNode>();
		if(start > end)
		{
			ret.add(null);
			return ret;
		}
		for(int i = start; i <= end; i++)
		{
			ArrayList<TreeNode> left = generate(start, i-1);
			ArrayList<TreeNode> right = generate(i+1, end);
			for(int j = 0; j < left.size(); j++)
			{
				for(int k = 0; k < right.size(); k++)
				{
					TreeNode root = new TreeNode(i);
					root.left = left.get(j);
					root.right = right.get(k);
					ret.add(root);
				}
			}
		}
		return ret;
	}
}

public class UniqueBinarySearchTreesII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
