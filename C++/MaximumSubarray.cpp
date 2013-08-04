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
	int maxSubArray(int A[], int n) {
		if(n <= 0)
			return 0;
		int maxsum = A[0];
		int sum = A[0];
		for(int i = 1; i < n; i++)
		{
			if(sum < 0)
			{
				sum = A[i];
			}
			else
			{
				sum += A[i];
			}
			if(sum > maxsum)
				maxsum = sum;
		}
		return maxsum;
	}
};