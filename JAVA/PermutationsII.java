import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(num == null || num.length == 0)
        	return ret;
        Arrays.sort(num);
        int len = num.length;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < len ;i++)
        {
        	list.add(num[i]);
        }
        ret.add(new ArrayList<Integer>(list));
        
        int pos1 = len-1;
        int pos2 = pos1;
        while(true)
        {
        	while(pos1 >= 1 && num[pos1] <= num[pos1-1])
        		pos1--;
        	if(pos1 == 0)
        		break;
        	pos1--;
        	while(num[pos2] <= num[pos1])
        		pos2--;
        	swap(num, pos1, pos2);
        	Arrays.sort(num, pos1+1, len);
        	list.clear();
            for(int i = 0; i < len ;i++)
            {
            	list.add(num[i]);
            }
            ret.add(new ArrayList<Integer>(list));
        	pos1 = len-1;
        	pos2 = pos1;
        }
        return ret;
    }
	private void swap(int[] num, int pos1, int pos2) {
		int temp = num[pos1];
		num[pos1] = num[pos2];
		num[pos2] = temp;
	}
}
public class PermutationsII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] num = {1,1};
		Solution sol = new Solution();
		System.out.println(sol.permuteUnique(num));
	}

}
