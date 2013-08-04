class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(prices == null || prices.length == 0)
        	return 0;
        int max = 0;
        int minIndex = 0;
        for(int i = 1; i < prices.length; i++)
        {
        	if(prices[i] < prices[minIndex])
        		minIndex = i;
        	else
        	{
        		int profit = prices[i] - prices[minIndex];
        		if(profit > max)
        			max = profit;
        	}
        }
        return max;
    }
}
public class BestTimetoBuyandSellStock {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
