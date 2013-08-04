class Solution {
	int total;
	int[] pos;
    public int totalNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        total = 0;
        if(n == 0)
        	return total;
        pos = new int[n]; 
        place(0, n);
        return total;
    }
	private void place(int index, int n) {
		if(index == n)
		{
			total++;
			return;
		}
		for(int i = 0; i < n; i++)
		{
			if(canPlace(index, i))
			{
				pos[index] = i;
				place(index+1, n);
			}
		}
	}
	private boolean canPlace(int row, int col) {
		for(int i = 0; i < row; i++)
		{
			int coli = pos[i];
			if(coli == col)
				return false;
			if((i+coli) == (row+col))
				return false;
			if((i-coli) == (row-col))
				return false;
		}
		return true;
		
	}
}
public class N_QueensII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
