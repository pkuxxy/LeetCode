class Solution {
    public boolean search(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A == null || A.length == 0)
        	return false;
        int l = 0;
        int r = A.length-1;
        if(A[l] == target)
        	return true;
        while(l < r && A[l] == A[r])
        	r--;
        while(l <= r)
        {
        	int mid = (l + r)/2;
        	if(A[mid] == target)
        		return true;
        	if(A[l] <= A[r])
        	{
        		if(A[mid] > target)
        			r = mid-1;
        		else
        			l = mid+1;
        	}
        	else
        	{
        		if(A[l] <= A[mid])
        		{
        			if(A[l] <= target && target <= A[mid])
        				r = mid-1;
        			else
        				l = mid+1;
        		}
        		else
        		{
        			if(A[mid] <= target && target <= A[r])
        				l = mid+1;
        			else
        				r = mid-1;
        		}
        	}
        }
        return false;
    }
}
public class SearchinRotatedSortedArrayII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
