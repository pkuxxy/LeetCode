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
		TreeLinkNode up = root;
		TreeLinkNode down = null;
		TreeLinkNode downFirst = null;
		while(up != null)
		{
			if(up.left != null)
			{
				if(down != null)
					down.next = up.left;
				down = up.left;
				if(downFirst == null)
					downFirst = down;
			}
			if(up.right != null)
			{
				if(down != null)
					down.next = up.right;
				down = up.right;
				if(downFirst == null)
					downFirst = down;
			}
			up = up.next;
		}
		connect(downFirst);
	}
}

public class PopulatingNextRightPointersinEachNodeII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
