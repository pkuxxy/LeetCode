class Solution {
    public int searchInsert(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	int i = 0;
        for(; i < A.length; i++)
        {
        	if(A[i] >= target)
        		return i;
        }
        return i;
    }
}
public class SearchInsertPosition {

}
