class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if (head == null)
			return null;
		ListNode pre = null;
		ListNode localHead = head;
		ListNode tail = head;
		int count = k-1;
		int times = listLengh(head) / k;
		while (times-- > 0) {
			count = k-1;
			while (count-- > 0) {
				ListNode next = tail.next;
				tail.next = next.next;
				next.next = localHead;
				localHead = next;
				if (pre == null)
					head = localHead;
				else
					pre.next = localHead;
				
			}
			pre = tail;
			tail = pre.next;
			localHead = tail;
		}
		return head;
	}

	private int listLengh(ListNode head) {
		int len = 0;
		while(head != null)
		{
			len++;
			head = head.next;
		}
		return len;
	}
}

public class ReverseNodesink_Group {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode p1 = new ListNode(2);
		head.next = p1;
		int k = 2;
		Solution sol = new Solution();
		sol.reverseKGroup(head, k);
	}

}
