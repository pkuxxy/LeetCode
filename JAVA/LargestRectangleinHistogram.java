class Solution {
    public int largestRectangleArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(height == null || height.length == 0)
        	return 0;
        int len = height.length;
        int[] h = new int[len+1];
        int[] w = new int[len+1];
        h[0] = -1;
        int top = 0;
        int ret = 0;
        for(int i = 0; i <= len; i++)
        {
        	int curh = (i == len)? 0 : height[i];
        	if(curh > h[top])
        	{
        		h[++top] = curh;
        		w[top] = 1;
        	}
        	else
        	{
        		int width = 0;
        		while(curh <= h[top])
        		{
        			ret = Math.max(ret, (w[top]+width)*h[top]);
        			width += w[top--];
        		}
        		h[++top] = curh;
        		w[top] = width+1;
        	}
        }
        return ret;
    }
}
public class LargestRectangleinHistogram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
