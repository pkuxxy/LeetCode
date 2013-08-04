class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
class Solution {
    public boolean isValidBST(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return isValid(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        	
    }

	private boolean isValid(TreeNode root, int minValue, int maxValue) {
		if(root == null)
			return true;
		return minValue < root.val && root.val < maxValue && isValid(root.left, minValue, root.val) && isValid(root.right, root.val, maxValue);
		
	}
}
public class ValidateBinarySearchTree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
