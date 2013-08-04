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

	private int getMaxArea(int[] a) {
		int len = a.length;
		int[] width = new int[len];
		Stack<Integer> stack = new Stack<Integer>();
		for(int i = 0; i < len ;i++)
		{
			if(stack.isEmpty())
			{
				stack.push(i);
				width[i] = 0;
			}
			else
			{
				while(!stack.isEmpty())
				{
					int top = stack.peek();
					if(a[i] <= a[top])
					{
						stack.pop();
					}
					else
					{
						stack.push(i);
						width[i] = i - top - 1;
						break;
					}
				}
				if(stack.isEmpty())
				{
					stack.push(i);
					width[i] = i;
				}
			}
		}
		stack.clear();
		for(int i = len-1; i >= 0 ;i--)
		{
			if(stack.isEmpty())
			{
				stack.push(i);
			}
			else
			{
				while(!stack.isEmpty())
				{
					int top = stack.peek();
					if(a[top] < a[i])
					{
						stack.push(i);
						width[i] += top - i - 1;
						break;
					}
					else
						stack.pop();
				}
				if(stack.isEmpty())
				{
					stack.push(i);
					width[i] += len - i - 1;
				}
			}
		}
		int max = 0;
		for(int i = 0; i < len ;i++)
		{
			max = Math.max(max, (width[i]+1)*a[i]);
		}
		return max;
	}
}
public class MaximalRectangle {

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
