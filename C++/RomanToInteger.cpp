#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
static map<char, int> vm;
void init()
{
		vm.insert(map<char, int>::value_type('I', 1));
		vm.insert(map<char, int>::value_type('V', 5));
		vm.insert(map<char, int>::value_type('X', 10));
		vm.insert(map<char, int>::value_type('L', 50));
		vm.insert(map<char, int>::value_type('C', 100));
		vm.insert(map<char, int>::value_type('D', 500));
		vm.insert(map<char, int>::value_type('M', 1000));
}
class Solution {
public:
    int romanToInt(string s) {
		init();
		if(s.size() == 0)
			return 0;
		int sum = 0;
		int first = vm.find(s[0])->second;
		for(int i = 1; i < s.size(); i++)
		{
			int second = vm.find(s[i])->second;
			if(first >= second)
				sum += first;
			else
				sum -= first;
			first = second;
		}
		sum += first;
		return sum;
    }
};
int main()
{
	string s = "I";
	Solution sol;
	cout<<sol.romanToInt(s);
	getchar();
}