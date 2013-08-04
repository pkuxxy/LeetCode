class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		ListNode p1 = head;
		ListNode p2 = head;
		ListNode pre = head;
		int i = 0;
		while(i++ < n)
		{
			p2 = p2.next;
		}
		while(p2 != null)
		{
			pre = p1;
			p1 = p1.next;
			p2 = p2.next;
		}
		if(pre == p1)
			return p1.next;
		pre.next = p1.next;
		return head;
		
	}
}

public class RemoveNthNodeFromEndofList {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
