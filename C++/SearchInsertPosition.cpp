#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
	int bsearch(int a[], int s, int e, int target)
	{
		if(s > e)
			return -1;
		int mid = (s+e)/2;
		if(a[mid] == target)
			return mid;
		else if(a[mid] < target)
		{
			int pos = bsearch(a, mid+1, e, target);
			return pos == -1 ? (e+1) : pos;
		}
		else
		{
			int pos = bsearch(a, s, mid-1, target);
			return pos == -1 ? s : pos;
		}
	}
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return bsearch(A, 0, n-1, target);
    }
};