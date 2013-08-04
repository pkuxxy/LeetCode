#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int bs(int a[], int s, int e, int target, bool left)
	{
		if(s > e)
			return -1;
		int mid = (s + e)/2;
		if(a[mid] == target)
		{
			if(left)
			{
				int pos = bs(a, s, mid-1, target, left);
				return pos == -1 ? mid : pos;
			}
			else
			{
				int pos = bs(a, mid+1, e, target, left);
				return pos == -1 ? mid : pos;
			}
		}
		else if(a[mid] < target)
		{
			return bs(a, mid+1, e, target, left);
		}
		else
			return bs(a, s, mid-1, target, left);
	}
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ret;
		ret.push_back(bs(A, 0, n-1, target, true));
		ret.push_back(bs(A, 0, n-1, target, false));
		return ret;
	}
};