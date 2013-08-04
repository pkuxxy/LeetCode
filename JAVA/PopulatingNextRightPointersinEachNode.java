import java.util.LinkedList;
import java.util.Queue;

class TreeLinkNode {
	int val;
	TreeLinkNode left, right, next;

	TreeLinkNode(int x) {
		val = x;
	}
}

class Solution {
	public void connect(TreeLinkNode root) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(root == null)
			return;
		Queue<TreeLinkNode> queue = new LinkedList<TreeLinkNode>();
		queue.add(root);
		int curLevel = 1;
		int nextLevel = 0;
		TreeLinkNode preNode = null;
		while(!queue.isEmpty())
		{
			curLevel--;
			TreeLinkNode node = queue.poll();
			if(preNode != null)
				preNode.next = node;
			preNode = node;
			if(node.left != null)
			{
				queue.add(node.left);
				nextLevel++;
			}
			if(node.right != null)
			{
				queue.add(node.right);
				nextLevel++;
			}
			if(curLevel == 0)
			{
				curLevel = nextLevel;
				nextLevel = 0;
				node.next = null;
				preNode = null;
			}
		}
	}
}

public class PopulatingNextRightPointersinEachNode {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
