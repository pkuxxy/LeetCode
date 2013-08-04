class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode swapPairs(ListNode head) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		ListNode p1 = head;
		ListNode p2 = p1.next;
		if(p2 == null)
			return p1;
		
		ListNode p3 = p2.next;
		p2.next = p1;
		p1.next = p3;
		head = p2;
		p2 = p3;
		if(p2 == null)
			return head;
		p3 = p2.next;
		while(p2 != null && p3 != null)
		{
			ListNode p4 = p3.next;
			p1.next = p3;
			p3.next = p2;
			p2.next = p4;
			p1 = p2;
			p2 = p4;
			if(p2 != null)
			{
				p3 = p2.next;
			}
		}
		return head;
	}
}

public class SwapNodesinPairs {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//{2,5,3,4,6,2,2};
		ListNode p1 = new ListNode(2);
		ListNode p2 = new ListNode(5);
		ListNode p3 = new ListNode(3);
		ListNode p4 = new ListNode(4);
		ListNode p5 = new ListNode(6);
		ListNode p6 = new ListNode(2);
		ListNode p7 = new ListNode(2);
		p1.next = p2;
		p2.next = p3;
		p3.next = p4;
		p4.next = p5;
		p5.next = p6;
		p6.next = p7;
		Solution sol = new Solution();
		ListNode head = sol.swapPairs(p1);
	}

}
