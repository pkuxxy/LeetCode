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
    bool search(int A[], int n, int target) {
        for(int i = 0; i < n ;i++)
		{
			if(A[i] == target)
				return true;
		}
		return false;
    }
};