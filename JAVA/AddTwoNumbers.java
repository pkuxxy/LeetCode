class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(l1 == null || l2 == null)
			return null;
		ListNode head = l1;
		ListNode pre = l1;
		while(l1 != null && l2 != null)
		{
			l1.val += l2.val;
			if(l1.val > 9)
			{
				l1.val %= 10;
				if(l1.next == null)
					l1.next = new ListNode(0);
				l1.next.val += 1;
			}
			pre = l1;
			l1 = l1.next;
			l2 = l2.next;
		}
		while(l1 != null)
		{
			if(l1.val > 9)
			{
				l1.val %= 10;
				if(l1.next == null)
					l1.next = new ListNode(0);
				l1.next.val += 1;
				l1 = l1.next;
			}
			else
				break;
		}
		if(l2 != null)
		{
			pre.next = l2;
		}
		return head;
	}
}

public class AddTwoNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
