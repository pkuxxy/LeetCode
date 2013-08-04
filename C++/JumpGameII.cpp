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
    int jump(int A[], int n) {
		int count = 0;
		int dest = 0;
		int start = 0;
		int tail = 0;
		while(dest < n-1)
		{
			count++;
			for(int i = start; i <= tail; i++)
			{
				int cur = i + A[i];
				if(cur > dest)
					dest = cur;
			}
			start = tail+1;
			tail = dest;
		}
		return count;
    }
};