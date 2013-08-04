import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;


class Solution {
	static class Node
	{
		public int index;
		public int val;
		public Node(int index, int val)
		{
			this.index = index;
			this.val = val;
		}
	}
	static class ValComparator implements Comparator<Node>
	{

		@Override
		public int compare(Node n1, Node n2) {
			return n1.val - n2.val;
		}
		
	}	

    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	Node[] nodes = new Node[numbers.length];
    	for(int i = 0; i < numbers.length; i++)
    	{
    		nodes[i] = new Node(i+1, numbers[i]);
    	}
    	
        Arrays.sort(nodes,new ValComparator());
        int start = 0;
        int end = numbers.length-1;
        while(start < end)
        {
        	int sum = nodes[start].val + nodes[end].val;
        	if(sum == target)
        	{
        		int[] ret = {nodes[start].index, nodes[end].index};
        		Arrays.sort(ret);
        		return ret;
        	}
        	else if(sum < target)
        		start++;
        	else
        		end--;
        }
        return null;
    }
}
public class TwoSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
