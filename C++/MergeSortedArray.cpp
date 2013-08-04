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
    void merge(int A[], int m, int B[], int n) {
        int tail = m+n-1;
		m--;
		n--;
		while(m >= 0 && n >= 0)
		{
			if(A[m] < B[n])
			{
				A[tail--] = B[n--];
			}
			else
				A[tail--] = A[m--];
		}
		while(m >= 0)
			A[tail--] = A[m--];
		while(n >= 0)
			A[tail--] = B[n--];
		
    }
};
int main()
{
	int a[]={1};
	int b[] = {2};
	Solution sol;
	sol.merge(a,1,b,1);
	getchar();
}