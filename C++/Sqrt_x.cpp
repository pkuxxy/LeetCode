#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        int l = 0; 
		int r = x;
		while(l <= r)
		{
			double mid = (l + r) / 2;
			double square = mid*mid;
			if(square <= x && (mid+1) * (mid+1) > x)
				return mid;
			else if(square <= x)
				l = mid+1;
			else
				r = mid-1;
		}
		return l;
    }
};