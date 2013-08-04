class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	int ret;
	public int maxPathSum(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(root == null)
			return 0;
		ret = Integer.MIN_VALUE;
		maxSum(root);
		return ret;
	}
	private int maxSum(TreeNode root) {
		if(root == null)
			return 0;
		int localSum = root.val;
		int left = maxSum(root.left);
		int right = maxSum(root.right);
		if(left > 0)
			localSum += left;
		if(right > 0)
			localSum += right;
		if(localSum > ret)
			ret = localSum;
		return root.val + Math.max(Math.max(0, left), right);
	}
}

public class BinaryTreeMaximumPathSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
