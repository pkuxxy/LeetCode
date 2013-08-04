class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(l1 == null && l2 == null)
			return null;
		ListNode head = null;
		if(l1 == null)
		{
			head = l2;
			l2 = l2.next;
		}
		else if(l2 == null)
		{
			head = l1;
			l1 = l1.next;
		}
		else
		{
			if(l1.val < l2.val)
			{
				head = l1;
				l1 = l1.next;
			}
			else
			{
				head = l2;
				l2 = l2.next;
			}
		}
		ListNode cur = head;
		while(l1 != null && l2 != null)
		{
			if(l1.val < l2.val)
			{
				cur.next = l1;
				l1 = l1.next;
			}
			else
			{
				cur.next = l2;
				l2 = l2.next;
			}
			cur = cur.next;
		}
		while(l1 != null)
		{
			cur.next = l1;
			l1 = l1.next;
			cur = cur.next;
		}
		while(l2 != null)
		{
			cur.next = l2;
			l2 = l2.next;
			cur = cur.next;
		}
		return head;
	}
}

public class MergeTwoSortedLists {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
