#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	void sortColors(int A[], int n) {
		int i = 0;
		int j = n-1;
		int k = n-1;
		while(i <= j)
		{
			if(A[i] == 2)
			{
				int tmp = A[i];
				A[i] = A[k];
				A[k] = tmp;
				k--;
				if(k < j)
					j = k;
			}
			else if(A[i] == 1)
			{
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
				j--;
			}
			else
				i++;
		}
	}
};