import java.util.Stack;

class Solution {
    public int maximalRectangle(char[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(matrix == null || matrix.length == 0)
        	return 0;
        int len1 = matrix.length;
        int len2 = matrix[0].length;
        int[] a = new int[len2];
        int maxArea = 0;
        for(int i = 0; i < len1; i++)
        {
        	for(int j = 0; j < len2; j++)
        	{
        		a[j] = matrix[i][j] == '1'?a[j]+1:0;
        	}
        	maxArea = Math.max(maxArea, getMaxArea(a));
        }
        return maxArea;
    }

	private int getMaxArea(int[] height) {
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
public class MaximalRectangle2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] matrix = {{'1'}};
		Solution sol = new Solution();
		System.out.println(""+sol.maximalRectangle(matrix));
	}

}
