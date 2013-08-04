class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(prices == null || prices.length < 2)
    		return 0;
    	int len = prices.length;
        int[] f1 = new int[len];
        int[] f2 = new int[len];
        f1[0] = 0;
        f2[len-1] = 0;
        int min = prices[0];
        for(int i = 1; i < len; i++)
        {
        	f1[i] = Math.max(f1[i-1], prices[i] - min);
        	min = Math.min(min, prices[i]);
        }
        int max = prices[len-1];
        for(int i = len-2; i >= 0; i--)
        {
        	f2[i] = Math.max(f2[i+1], max - prices[i]);
        	max = Math.max(max, prices[i]);
        }
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
        	sum = Math.max(sum, f1[i] + f2[i]);
        }
        return sum;
    }
}
public class BestTimetoBuyandSellStockIII {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = {1,2};
		Solution sol = new Solution();
		System.out.println(""+sol.maxProfit(prices));
	}

}
