class Solution {
    public int search(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return bsearch(A, 0, A.length-1, target);
    }

	private int bsearch(int[] a, int start, int end, int value) {
		if(start > end)
			return -1;
		int mid = (start + end)/2;
		if(a[mid] == value)
			return mid;
		else if(a[start] <= a[mid])
		{
			if(a[start] <= value && value <= a[mid])
				return bsearch(a, start, mid-1, value);
			else
				return bsearch(a, mid+1, end, value);
		}
		else
		{
			if(a[mid] <= value && value <= a[end])
				return bsearch(a, mid+1, end, value);
			else
				return bsearch(a, start, mid-1, value);
		}
	}
}
public class SearchinRotatedSortedArray {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
