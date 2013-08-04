class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if(!len)
            return len;
        int ret = 0;
        int minp = prices[0];
        int maxp = prices[len-1];
        vector<int> left(len,0);
        vector<int> right(len, 0);
        for(int i = 1; i < len; i++)
        {
            minp = min(minp, prices[i]);
            left[i] = max(left[i-1], prices[i] - minp);
        }
        for(int i = len-2; i >= 0; i--)
        {
            maxp = max(maxp, prices[i]);
            right[i] = max(right[i+1], maxp - prices[i]);
        }
        for(int i = 0; i < len; i++)
            ret = max(ret, left[i]+right[i]);
        return ret;
        
    }
};