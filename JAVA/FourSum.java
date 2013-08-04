import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
    	if(num == null || num.length < 4)
    		return ret;
    	Arrays.sort(num);
        int len = num.length;
        for(int i = 0; i < len ;i++)
        {
        	if(i > 0 && num[i] == num[i-1])
        		continue;
        	if(num[i] > 0 &&  num[i] > target)
        		break;
        	if(4*num[i] > target)
        		break;
        	for(int j = i+1; j < len; j++)
        	{
        		if(j > i+1 && num[j] == num[j-1])
        			continue;
        		if(3*num[j] + num[i] > target)
        			break;
        		int k = j+1;
        		int m = len-1;
        		while(k < m)
        		{
        			if(k > j+1 && num[k] == num[k-1])
        			{
        				k++;
        				continue;
        			}
        			if(m < len-1 && num[m] == num[m+1])
        			{
        				m--;
        				continue;
        			}
        			int sum = num[i] + num[j] + num[k] + num[m];
        			if(sum == target)
        			{
        				ArrayList<Integer> cur = new ArrayList<Integer>();
        				cur.add(num[i]);
        				cur.add(num[j]);
        				cur.add(num[k]);
        				cur.add(num[m]);
        				ret.add(cur);
        				k++;
        			}
        			else if(sum < target)
        				k++;
        			else
        				m--;
        		}
        	}
        }
        return ret;
    }
}
public class FourSum {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//[-1,2,2,-5,0,-1,4], 3
		//[-1,-5,-5,-3,2,5,0,4], -7
		//[1,-2,-5,-4,-3,3,3,5], -11
		//[-7,0,-5,0,-8,-3,-5,1,4,-2,-6,10], -12  [-8,-6,-2,4]
		int[] num = {-7,0,-5,0,-8,-3,-5,1,4,-2,-6,10};
		int target = -12;
		Solution sol = new Solution();
		System.out.println(sol.fourSum(num, target));
	}

}
