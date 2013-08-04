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
	int dc(int a[], int l, int r)
	{
		if(l == r)
			return a[l];
		int mid = (l + r) / 2;
		int leftMax = dc(a, l, mid);
		int rightMax = dc(a, mid+1, r);
		int midLeft = a[mid];
		int sum = a[mid];
		for(int i = mid-1; i >= l; i--)
		{
			sum += a[i];
			if(sum > midLeft)
				midLeft = sum;
		}
		int midRight = a[mid+1];
		sum = a[mid+1];
		for(int i = mid+2; i <= r; i++)
		{
			sum += a[i];
			if(sum > midRight)
				midRight = sum;
		}
		return max(midLeft+midRight, max(leftMax, rightMax));
	}
	int maxSubArray(int A[], int n) {
		return dc(A, 0, n-1);
	}
};
int main()
{
	int a[] = {2,-1,1,1};
	Solution sol;
	cout<<sol.maxSubArray(a, 4);
	getchar();
}