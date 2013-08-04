#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int bs(vector<unsigned>& f, int s, int e, int target)
	{
		if(s > e)
			return -1;
		int mid = (s+e)/2;
		if(f[mid] == target)
			return mid;
		else if(f[mid] < target)
		{
			int pos = bs(f, mid+1, e, target);
			return pos == -1? mid:pos;
		}
		else
		{
			return bs(f, s, mid-1, target);
		}
	}
    int divide(int dividend, int divisor) {
        bool sign = true;
		if((dividend < 0 && divisor > 0) ||  (dividend > 0 && divisor < 0))
			sign = false;
		unsigned a = abs(dividend);
		unsigned b = abs(divisor);
		vector<unsigned> f(100);
		f[0] = b;
		int size = 1;
		while(f[size-1] < a)
		{
			f[size] = f[size-1] + f[size-1];
			size++;
		}
		unsigned ret = 0;
		while(a > 0)
		{
			int pos = bs(f, 0, size-1, a);
			if(pos == -1)
				break;
			ret |= 1<<pos;
			a -= f[pos];
		}
		return sign?ret:-ret;
    }
};
int main()
{
	int a = 2147483647;
	int b = 1;
	Solution sol;
	cout<<sol.divide(a, b);
	getchar();
}