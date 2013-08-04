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
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tail = 0;
		int i = 0;
		while(i < n-1)
		{
			A[tail++] = A[i];
			if(A[i] == A[i+1])
			{	
				while(i < n-1 && A[i] == A[i+1])
				{
					i++;
				}
			}
			else
				i++;
		}
		if(i == n-1)
			A[tail++] = A[i];
		return tail;
    }
};