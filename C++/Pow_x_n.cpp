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
	double pow(double x, int n) {
		if(n == 0)
			return 1;
		if(n < 0 && n != -2147483648)
			return 1/pow(x, -n);

		double half = pow(x, n/2);
		if(n % 2 == 1)
			return x * half * half;
		else
			return half * half;
	}
};