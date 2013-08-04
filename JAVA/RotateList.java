class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode rotateRight(ListNode head, int n) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null || n == 0)
			return head;
		ListNode l1 = head;
		ListNode l2 = head;
		int len = listLen(head);
		n %= len;
		if(n == 0)
			return head;
		while(n-- > 0)
		{
			l2 = l2.next;
		}
		while(l2.next != null)
		{
			l1 = l1.next;
			l2 = l2.next;
		}
		ListNode oldHead = head;
		head = l1.next;
		l1.next = l2.next;
		l2.next = oldHead;
		return head;
	}

	private int listLen(ListNode head) {
		// TODO Auto-generated method stub
		int len = 0;
		while(head != null)
		{
			head = head.next;
			len++;
		}
		return len;
	}
}

public class RotateList {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
