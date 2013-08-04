#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		int power = 1;
		while(x/power >= 10)
			power *= 10;
		while(x)
		{
			if(x/power != x%10)
				return false;
			x %= power;
			x /= 10;
			power /= 100;
		}
		return true;
    }
};
int main()
{
	int x = 1001;
	Solution sol;
	cout<<sol.isPalindrome(x);
	getchar();
}