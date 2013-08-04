class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	
	public TreeNode sortedListToBST(ListNode head) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		int len = calLen(head);
		return makeTree(head, 0, len-1);
	}

	private TreeNode makeTree(ListNode head, int start, int end) {
		if(start > end)
			return null;
		int mid = (start + end) / 2;
		ListNode midNode = head;
		for(int i = start; i < mid; i++)
			midNode = midNode.next;
		TreeNode root = new TreeNode(midNode.val);
		root.left = makeTree(head, start, mid-1);
		root.right = makeTree(midNode.next, mid+1, end);
		return root;
	}

	private int calLen(ListNode head) {
		int len = 0;
		while(head != null)
		{
			len++;
			head = head.next;
		}
		return len;
	}
}

public class ConvertSortedListtoBinarySearchTree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode p1 = new ListNode(1);
		ListNode p2 = new ListNode(3);
		p1.next = p2;
		Solution sol = new Solution();
		sol.sortedListToBST(p1);
	}

}
