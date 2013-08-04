class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	TreeNode tmp1 = null;
	TreeNode tmp2 = null;
	TreeNode tmp = null;
	boolean found = false;
	boolean first = true;
	public void recoverTree(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(root == null)
			return;
		found = false;
		first = true;
		check1(root);
		found = false;
		first = true;
		check2(root);
		if(tmp1 != null && tmp2 != null)
		{
			int t = tmp1.val;
			tmp1.val = tmp2.val;
			tmp2.val = t;
		}
	}

	private void check1(TreeNode root) {
		if(found || root == null)
			return;
		check1(root.left);
		if(first)
		{
			tmp = root;
			first = false;
		}
		else
		{
			if(root.val <= tmp.val)
			{
				tmp1 = tmp;
				found = true;
				return;
			}
			else
				tmp = root;
		}
		check1(root.right);
	}
	private void check2(TreeNode root) {
		if(found || root == null)
			return;
		check2(root.right);
		if(first)
		{
			tmp = root;
			first = false;
		}
		else
		{
			if(root.val >= tmp.val)
			{
				tmp2 = tmp;
				found = true;
			}
			else
				tmp = root;
		}
		check2(root.left);
	}
}

public class RecoverBinarySearchTree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
