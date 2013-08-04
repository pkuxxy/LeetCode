import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(num == null || num.length < 3)
        	return 0;
        Arrays.sort(num);
        int len = num.length;
        int sum = num[0] + num[1] + num[2];
        int min = Math.abs(target - sum);
        for(int i = 0; i < num.length; i++)
        {
        	if(i > 0 && num[i] == num[i-1])
        		continue;
        	int j = i + 1;
        	int k = len - 1;
        	while(j < k)
        	{
        		if(j > i+1 && num[j] == num[j-1])
        		{
        			j++;
        			continue;
        		}
        		if(k < len-1 && num[k] == num[k-1])
        		{
        			k--;
        			continue;
        		}
        		int cur = num[i] + num[j] + num[k];
        		if(Math.abs(target - cur) < min)
        		{
        			min = Math.abs(target - cur);
        			sum = cur;
        		}
        		if(cur == target)
        			return sum;
        		else if(cur < target)
        		{
        			j++;
        		}
        		else
        			k--;
        	}
        }
        return sum;
    }
}
public class ThreeSumClosest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
