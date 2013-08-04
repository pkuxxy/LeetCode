class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	public void flatten(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		root = preorder(root);
	}

	private TreeNode preorder(TreeNode root) {
		if(root == null)
			return null;
		TreeNode rightSub = root.right;
		root.right = preorder(root.left);
		root.left = null;
		TreeNode rightMost = getRightMost(root);
		rightMost.right = preorder(rightSub);
		return root;
	}

	private TreeNode getRightMost(TreeNode root) {
		while(root.right != null)
			root = root.right;
		return root;
	}

}

public class FlattenBinaryTreetoLinkedList {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
