#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int len = height.size();
		if(!len)
			return 0;
		vector<int> h(len+1,-1);
		vector<int> w(len+1,0);
		int top = 0;
		int maxSum = 0;
		for(int i = 0; i <= len; i++)
		{
			int curh = (i == len)? 0:height[i];
			if(curh > h[top])
			{
				h[++top] = curh;
				w[top] = 1;
			}
			else
			{
				int width = 0;
				while(curh <= h[top])
				{
					maxSum = max(maxSum, (w[top] + width)*h[top]);
					width +=  w[top--];
				}
				h[++top] = curh;
				w[top] = width+1;
			}
		}
		return maxSum;
	}
};