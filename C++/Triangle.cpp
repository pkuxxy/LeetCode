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
    int minimumTotal(vector<vector<int> > &triangle) {
		int len = triangle.size();
		if(!len)
			return 0;
		vector<int> pre;
		pre.push_back(triangle[0][0]);
		for(int i = 1; i < len; i++)
		{
			vector<int> cur;
			cur.push_back(pre[0] + triangle[i][0]);
			for(int j = 1; j < i; j++)
			{
				cur.push_back(min(pre[j], pre[j-1])+triangle[i][j]);
			}
			cur.push_back(pre[i-1]+triangle[i][i]);
			pre = cur;
		}
		int minSum = pre[0];
		for(int i = 1; i < pre.size(); i++)
		{
			if(pre[i] < minSum)
				minSum = pre[i];
		}
		return minSum;
    }
};