class Solution {
    public void sortColors(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i = 0;
        int j = A.length-1;
        int k = j;
        while(i <= j)
        {
        	if(A[i] == 2)
        	{
        		int tmp = A[i];
        		A[i] = A[k];
        		A[k] = tmp;
        		k--;
        		if(k < j)
        			j = k;
        	}
        	else if(A[i] == 1)
        	{
        		int tmp = A[i];
        		A[i] = A[j];
        		A[j] = tmp;
        		j--;
        	}
        	else
        		i++;
        }
    }
}
public class SortColors {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
