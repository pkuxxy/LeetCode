#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp = 0;
		int minp = 1000000000;
		for(int i = 0; i < prices.size(); i++)
		{
			if(prices[i] < minp)
			{
				minp = prices[i];
			}
			else
			{
				int cur = prices[i] - minp;
				maxp = maxp > cur ? maxp : cur;
			}
		}
		return maxp;
    }
};