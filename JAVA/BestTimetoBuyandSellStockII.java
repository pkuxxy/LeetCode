class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	//1,2,4,2,5,7,2,4,9,0,9
    	if(prices == null || prices.length == 0)
    		return 0;
        int sum = 0;
        int start = prices[0];
        int i = 1;
        for(; i < prices.length; i++)
        {
        	if(prices[i] >= prices[i-1])
        		continue;
        	if(prices[i-1] > start)
        		sum += prices[i-1] - start;
        	start = prices[i];
        }
        if(prices[i-1] > start)
        	sum += prices[i-1] - start;
        return sum;
    }
}
public class BestTimetoBuyandSellStockII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
