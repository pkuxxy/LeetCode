import java.awt.List;

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode reverseBetween(ListNode head, int m, int n) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		int count = 1;
		ListNode pre = null;
		ListNode p = head;
		
		while(count < m)
		{
			count++;
			pre = p;
			p = p.next;
		}
		ListNode tail = p;
		while(count < n)
		{
			
			ListNode next = tail.next;
			if(pre == null)
			{
				p = head;
				head = next;	
			}
			else
			{
				p = pre.next;
				pre.next = next;
			}
			tail.next = next.next;
			next.next = p;
			count++;
		}
		
		return head;
	}
}

public class ReverseLinkedListII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ListNode p1 = new ListNode(1);
		ListNode p2 = new ListNode(2);
		ListNode p3 = new ListNode(3);
		ListNode p4 = new ListNode(4);
		ListNode p5 = new ListNode(5);
		p1.next = p2;
		p2.next = p3;
		p3.next = p4;
		p4.next = p5;
		Solution sol = new Solution();
		sol.reverseBetween(p1, 3, 4);
	}

}
