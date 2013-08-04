class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	public TreeNode sortedArrayToBST(int[] num) {
		// Start typing your Java solution be		
		// DO NOT write main() function
		if(num == null || num.length == 0)
			return null;

		return insert(num, 0, num.length - 1);
	}

	private TreeNode insert(int[] num, int start, int end) {
		if(start > end)
			return null;
		if(start == end)
		{
			TreeNode ret = new TreeNode(num[start]);
			ret.left = null;
			ret.right = null;
			return ret;
		}
		int mid = (start + end + 1) / 2;
		TreeNode ret = new TreeNode(num[mid]);
		ret.left = insert(num, start, mid-1);
		ret.right = insert(num, mid+1, end);
		return ret;
		
	}
}

public class ConvertSortedArraytoBinarySearchTree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
