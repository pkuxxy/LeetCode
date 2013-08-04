class Solution {
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(height == null || height.length == 0)
        	return 0;
        int max = 0;
        int i = 0; 
        int j = height.length-1;
        while(i < j)
        {
        	int minH = Math.min(height[i], height[j]);
        	int capacity = minH * (j - i);
        	if(capacity > max)
        		max = capacity;
        	if(height[i] < height[j])
        	{
        		i++;
        		while(i < j && height[i] <= minH)
        			i++;
        	}
        	else
        	{
        		j--;
        		while(i < j && height[j] <= minH)
        			j--;
        	}
        }
        return max;
    }
}
public class ContainerWithMostWater {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
