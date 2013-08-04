class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}
class Solution {
	public TreeNode buildTree(int[] inorder, int[] postorder) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(inorder == null || inorder.length != postorder.length)
    		return null;
        return build(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }

	private TreeNode build(int[] inorder, int start1, int end1, int[] postorder,
			int start2, int end2) {
		if(start1 > end1 || start2 > end2)
			return null;
		TreeNode root = new TreeNode(postorder[end2]);
		int index = -1;
		for(int i = start1; i <= end1; i++)
		{
			if(inorder[i] == root.val)
			{
				index = i;
				break;
			}
		}
		root.left = build(inorder, start1, index-1, postorder, start2, start2+(index-start1)-1);
		root.right = build(inorder, index+1, end1, postorder, start2+(index-start1), end2-1);
		return root;
	}
	
}

public class ConstructBinaryTreefromInorderandPostorderTraversal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
