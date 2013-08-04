import java.util.HashSet;
import java.util.Set;

class Solution {
	Set<Integer> set = new HashSet<Integer>();
    public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        set.clear();
        for(int i : num)
        {
        	set.add(i);
        }
        int max = 0;
        for(int i : num)
        {
        	max = Math.max(max, getCount(num, i, false)+getCount(num, i+1, true));
        }
        return max;
    }

	private int getCount(int[] num, int v, boolean asc) {
		int count = 0;
		while(set.contains(v))
		{
			set.remove(v);
			count++;
			v = asc ? v+1:v-1;
		}
		return count;
	}
}
public class LongestConsecutiveSequence {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
