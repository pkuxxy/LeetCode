#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
		if(!n)
			return 0;
        vector<int> h1(n,0);
		vector<int> h2(n,0);
		h1[0] = A[0];
		for(int i = 1; i < n; i++)
		{
			h1[i] = max(h1[i-1], A[i]);
		}
		h2[n-1] = A[n-1];
		for(int i = n-2; i >= 0; i--)
		{
			h2[i] = max(h2[i+1], A[i]);
		}
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum += min(h1[i],h2[i]) - A[i];
		}
		return sum;
    }
};