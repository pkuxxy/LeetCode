import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}


class Solution {
	static class NodeComparator implements Comparator<ListNode>
	{

		@Override
		public int compare(ListNode o1, ListNode o2) {
			return o1.val - o2.val;
		}
		
	}
	public ListNode mergeKLists(ArrayList<ListNode> lists) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if(lists == null || lists.size() == 0)
			return null;
		int size = lists.size();
		PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(size, new NodeComparator());
		
		for(int i = 0; i < size; i++)
		{
			if(lists.get(i) == null)
				continue;
			heap.add(lists.get(i));
		}
		ListNode head = null;
		ListNode cur = null;
		while(!heap.isEmpty())
		{
			ListNode newNode = heap.poll();
			if(head == null)
			{
				head = newNode;
				cur = head;
				if(cur.next != null)
					heap.add(cur.next);
			}
			else
			{
				cur.next = newNode;
				cur = newNode;
				if(cur.next != null)
					heap.add(cur.next);
			}
		}
		return head;
	}
}

public class MergekSortedLists {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
