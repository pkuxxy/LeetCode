class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		ListNode pre = null;
		ListNode p = head;
		while(p != null)
		{
			boolean tag = false;
			while(p != null && p.next != null)
			{
				if(p.val == p.next.val)
				{
					tag = true;
					p = p.next;
				}
				else
					break;
			}
			if(tag)
			{
				if(pre != null)
					pre.next = p.next;
			}
			else
			{
				if(pre == null)
				{
					head = p;
				}
				pre = p;
			}
			p = p.next;
		}
		if(pre == null)
			return null;
		return head;
	}
}

public class RemoveDuplicatesfromSortedListII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
