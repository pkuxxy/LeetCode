import java.util.ArrayList;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(num == null || num.length == 0)
        	return ret;
        solve(0, num);
        return ret;
    }
	private void solve(int index, int[] num) {
		if(index == num.length)
		{
			ArrayList<Integer> cur = new ArrayList<Integer>();
			for(int i = 0; i < num.length ;i++)
			{
				cur.add(num[i]);
			}
			ret.add(cur);
			return;
		}
		for(int i = index; i < num.length; i++)
		{
			swap(num, index, i);
			solve(index+1, num);
			swap(num, index, i);
		}
	}
	private void swap(int[] num, int i, int j) {
		int tmp = num[i];
		num[i] = num[j];
		num[j] = tmp;
	}
}
public class Permutations {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] num = {1};
		Solution sol = new Solution();
		System.out.println(sol.permute(num));
	}

}
