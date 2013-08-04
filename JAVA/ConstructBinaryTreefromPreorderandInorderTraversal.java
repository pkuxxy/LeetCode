class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(preorder == null || preorder.length != inorder.length)
    		return null;
        return build(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
    }

	private TreeNode build(int[] preorder, int start1, int end1, int[] inorder,
			int start2, int end2) {
		if(start1 > end1 || start2 > end2)
			return null;
		TreeNode root = new TreeNode(preorder[start1]);
		int leftEnd = -1;
		for(int i = start2; i <= end2; i++)
		{
			if(inorder[i] == root.val)
			{
				leftEnd = i;
				break;
			}
		}
		root.left = build(preorder, start1+1, start1+(leftEnd-start2), inorder, start2, leftEnd-1);
		root.right = build(preorder, start1+(leftEnd-start2)+1, end1, inorder, leftEnd+1, end2);
		return root;
	}
}
public class ConstructBinaryTreefromPreorderandInorderTraversal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] preorder = {1,2};
		int[] inorder = {2,1};
		Solution sol = new Solution();
		sol.buildTree(preorder, inorder);
	}

}
