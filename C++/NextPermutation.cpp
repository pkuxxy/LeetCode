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
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
		if(len <= 1)
			return;
		int i = len-2;
		while(i>=0 && num[i] >= num[i+1])
			i--;
		if(i == -1)
		{
			reverse(num.begin(), num.end());
			return;
		}
		int j = len-1;
		while(num[j] <= num[i])
			j--;
		swap(num[i], num[j]);
		reverse(num.begin()+i+1,num.end());
    }
};
int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	Solution sol;
	sol.nextPermutation(num);
	getchar();
}