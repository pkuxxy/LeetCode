
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int len = prices.size();
       if(!len)
       return 0;
       int minPrice = prices[0];
       int maxProfit = 0;
       for(int i = 1; i < len; i++)
       {
           minPrice = min(minPrice, prices[i]);
           maxProfit = max(maxProfit, prices[i] - minPrice);
       }
       return maxProfit;
    }
};