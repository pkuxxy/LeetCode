class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(!len)
            return 0;
        int profit = 0;
        for(int i = 1; i < len; i++)
        {
            profit += max(0,prices[i] - prices[i-1]);
        }
        return profit;
    }
};