import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        if(num == null || num.length == 0)
        	return ret;
        Arrays.sort(num);
        int len = num.length;
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
        	if(i > 0 && num[i] == num[i-1])
        		continue;
        	int j = i+1;
        	int k = len-1;
        	while(j < k)
        	{
            	if(j > i+1 && num[j] == num[j-1])
            	{
            		j++;
            		continue;
            	}
            	if(k < len-1 && num[k] == num[k+1])
            	{
            		k--;
            		continue;
            	}

        		sum = num[i] + num[j] + num[k];
        		if(sum == 0)
        		{
        			ArrayList<Integer> cur = new ArrayList<Integer>();
        			cur.add(num[i]);
        			cur.add(num[j]);
        			cur.add(num[k]);
        			ret.add(cur);
        			j++;
        		}
        		else if(sum < 0)
        			j++;
        		else
        			k--;
        	}
        }
        return ret;
        
    }
}
public class ThreeSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
