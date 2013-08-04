class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	public ListNode partition(ListNode head, int x) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(head == null)
			return null;
		ListNode pre = null;
		ListNode p = head;
		ListNode tail = head;
		while(tail.next != null)
			tail = tail.next;
		ListNode q = tail;
		while(p != q)
		{
			if(p.val >= x)
			{
				tail.next = p;
				tail = p;
				ListNode next = p.next;
				if(pre == null)
					head = next;
				else
					pre.next = next;
				p.next = null;
				p = next;
			}
			else
			{
				pre = p;
				p = p.next;
			}
		}
		if(q.val >= x && tail != q){
			tail.next = q;
			ListNode next = q.next;
			if(pre == null)
				head = next;
			else
				pre.next = next;
			q.next = null;
		}
		return head;
	}
}

public class PartitionList {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
