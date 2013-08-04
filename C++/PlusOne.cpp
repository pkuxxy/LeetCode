#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int i = digits.size()-1;
		digits[i] += 1;

		for(; i >0 ;i--)
		{
			if(digits[i] > 9)
			{
				digits[i] %= 10;
				digits[i-1] += 1;
			}
			else
				break;
		}
		if(digits[0] > 9)
		{
			digits[0] %= 10;
			vector<int>::iterator iter = digits.begin();
			digits.insert(iter,1);
		}
		return digits;
    }
};