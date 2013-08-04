#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int* ways = new int[n];
		ways[0] = 1;
		ways[1] = 2;
		for(int i = 2; i < n; i++)
		{
			ways[i] = ways[i-1] + ways[i-2];
		}
		return ways[n-1];
    }
};