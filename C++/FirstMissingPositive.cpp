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
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
			return 1;
		int i = 0;
		while(i < n)
		{
			if(A[i] < 0 || A[i] >= n || A[i] == i || A[i] == A[A[i]])
				i++;
			else
				swap(A[i],A[A[i]]);
		}
		for(int i = 1; i < n; i++)
		{
			if(A[i] != i)
				return i;
		}
		if(A[0] == n)
			return n+1;
		else
			return n;
    }
};