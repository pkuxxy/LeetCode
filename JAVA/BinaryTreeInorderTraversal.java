import java.util.ArrayList;
import java.util.Stack;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	public ArrayList<Integer> inorderTraversal(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ArrayList<Integer> ret = new ArrayList<Integer>();
		if(root == null)
			return ret;
		Stack<TreeNode> stack = new Stack<TreeNode>();
		TreeNode node = root;
		while(!stack.isEmpty() || node != null)
		{
			if(node != null)
			{
				stack.push(node);
				node = node.left;
			}
			else
			{
				node = stack.pop();
				ret.add(node.val);
				node = node.right;
			}
		}
		return ret;
	}
}

public class BinaryTreeInorderTraversal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
