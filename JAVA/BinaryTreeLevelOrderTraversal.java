import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

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
	public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		if(root == null)
			return ret;
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.add(root);
		int curLevelCount = 1;
		int nextLevelCount = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		while(!queue.isEmpty())
		{
			curLevelCount--;
			TreeNode node = queue.poll();
			list.add(node.val);
			if(node.left != null)
			{
				queue.add(node.left);
				nextLevelCount++;
			}
			if(node.right != null)
			{
				queue.add(node.right);
				nextLevelCount++;
			}
			if(curLevelCount == 0)
			{
				curLevelCount = nextLevelCount;
				nextLevelCount = 0;
				ret.add(new ArrayList<Integer>(list));
				list.clear();
			}
		}
		return ret;
	}
}

public class BinaryTreeLevelOrderTraversal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
