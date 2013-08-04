#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		if(num.size() < 3)
			return 0;
		int closest = 1000000000;
		sort(num.begin(), num.end());
		for(int i = 0; i < num.size() - 2; i++)
		{
			if(i != 0 && num[i] == num[i-1])
				continue;
			int j = i + 1;
			int k = num.size()-1;
			while(j < k)
			{
				if(j != (i + 1) && num[j] == num[j-1])
				{
					j++;
					continue;
				}
				if(k != (num.size()-1) && num[k] == num[k+1])
				{
					k--;
					continue;
				}
				int sum = num[i] + num[j] + num[k];
				if(sum == target)
					return sum;
				else if(sum < target)
				{
					int diff = abs(sum - target);
					if(diff < abs(closest - target))
						closest = sum;
					j++;
				}
				else 
				{
					int diff = abs(sum - target);
					if(diff < abs(closest - target))
						closest = sum;
					k--;
				}
			}

		}
		return closest;
	}
};