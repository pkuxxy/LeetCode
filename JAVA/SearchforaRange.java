class Solution {
    public int[] searchRange(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	
        int left = bsearch(A, 0, A.length-1, target, true);
        int right = bsearch(A, 0, A.length-1, target, false);
        int[] ret = {left,right};
        return ret;
    }

	private int bsearch(int[] a, int left, int right, int target, boolean findLeft) {
		if(left > right)
			return -1;
		int mid = (left + right) / 2;
		if(a[mid] == target)
		{
			int pos = findLeft ? bsearch(a, left, mid-1, target, findLeft) : bsearch(a, mid+1, right, target, findLeft);
			return pos == -1 ? mid : pos;
				
		}
		else if(a[mid] < target)
			return bsearch(a, mid+1, right, target, findLeft);
		else
			return bsearch(a, left, mid-1, target, findLeft);
	}
}
public class SearchforaRange {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
