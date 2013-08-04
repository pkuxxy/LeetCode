import java.util.ArrayList;
import java.util.Collections;
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

	public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		if (root == null)
			return ret;
		boolean tag = false;
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		int curLevel = 1;
		int nextLevel = 0;
		q.add(root);
		ArrayList<Integer> list = new ArrayList<Integer>();
		while (!q.isEmpty()) {
			curLevel--;
			TreeNode node = q.poll();
			list.add(node.val);
			if (node.left != null) {
				q.add(node.left);
				nextLevel++;
			}
			if (node.right != null) {
				q.add(node.right);
				nextLevel++;
			}

			if (curLevel == 0) {
				if(tag)
					Collections.reverse(list);
				ret.add(new ArrayList<Integer>(list));
				list.clear();
				curLevel = nextLevel;
				nextLevel = 0;
				tag = !tag;
			}
		}
		return ret;
	}
}

public class BinaryTreeZigzagLevelOrderTraversal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TreeNode root = new TreeNode(1);
		TreeNode n2 = new TreeNode(2);
		TreeNode n3 = new TreeNode(3);
		TreeNode n4 = new TreeNode(4);
		TreeNode n5 = new TreeNode(5);
		root.left = n2;
		root.right = n3;
	}

}
