import java.util.ArrayList;

class Solution {
	ArrayList<String[]> ret = new ArrayList<String[]>();
	int[] pos;
    public ArrayList<String[]> solveNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        if(n == 0)
        	return ret;
        pos = new int[n]; 
        place(0, n);
        return ret;
    }
	private void place(int index, int n) {
		if(index == n)
		{
			String[] str = new String[n];
			for(int i = 0; i < n; i++)
			{
				str[i] = new String();
				for(int j = 0; j < n ;j++)
				{
					if(j == pos[i])
						str[i] += 'Q';
					else
						str[i] += '.';
				}
			}
			ret.add(str);
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
public class N_Queens {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		System.out.println(sol.solveNQueens(1));
	}

}
