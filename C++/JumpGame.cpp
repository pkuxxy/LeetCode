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
    bool canJump(int A[], int n) {
		if(n <= 1)
			return true;
        int dest = 0;
		for(int i = 0; i < n; i++)
		{
			if(i > dest)
				return false;
			int cur = A[i] + i;
			if(cur > dest)
				dest = cur;
			if(dest >= n-1)
				return true;
		}
		return false;
    }
};