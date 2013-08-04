#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    int reverse(int x) {
		bool sign = x >= 0 ? true : false;
		x = abs(x);
		char str[33];
		int len = 0;
		while(x)
		{
			str[len++] = x % 10;
			x /= 10;
		}
		int ret = 0;
		for(int i = 0; i < len; i++)
		{
			ret *= 10;
			ret += str[i];
		}
		return sign ? ret : -ret;
    }
};