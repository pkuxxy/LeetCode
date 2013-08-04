#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size() <= 0)
			return 0;
		int len = prices.size();
		vector<int> f1(len), f2(len);
		
		int minp = prices[0];
		f1[0] = 0;
		for(int i = 1; i < len; i++)
		{
			f1[i] = max(f1[i-1], prices[i] - minp);
			minp = min(minp, prices[i]);
		}
		f2[len-1] = 0;
		int maxp = prices[len-1];
		for(int i = len-2; i >= 0; i--)
		{
			f2[i] = max(f2[i+1], maxp - prices[i]);
			maxp = max(maxp, prices[i]);
		}
		int sum = 0;
		for(int i = 0; i < len; i++)
		{
			sum = max(sum, f1[i] + f2[i]);
		}
		return sum;
    }
};
int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	Solution sol;
	cout<<sol.maxProfit(prices);
	getchar();
}