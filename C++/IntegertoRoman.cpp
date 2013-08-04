#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
static map<int, char> vm;
void init()
{
	vm.insert(map<int, char>::value_type(1, 'I'));
	vm.insert(map<int, char>::value_type(5, 'V'));
	vm.insert(map<int, char>::value_type(10, 'X'));
	vm.insert(map<int, char>::value_type(50, 'L'));
	vm.insert(map<int, char>::value_type(100, 'C'));
	vm.insert(map<int, char>::value_type(500, 'D'));
	vm.insert(map<int, char>::value_type(1000, 'M'));
}
class Solution {
public:
	string intToRoman(int num) {
		init();
		string ret;
		int power = 1;
		while(power*10 <= num)
			power *= 10;
		while(num)
		{
			int bit = num/power;
			char ch = vm.find(power)->second;
			if(bit <= 0)
			{
			}
			else if(bit <= 3)
			{
				for(int i = 0; i < bit; i++)
					ret.push_back(ch);
			}
			else if(bit == 4)
			{
				char big = vm.find(5*power)->second;
				ret.push_back(ch);
				ret.push_back(big);
			}
			else if(bit <= 8)
			{
				char big = vm.find(5*power)->second;
				ret.push_back(big);
				for(int i = 0; i < bit-5; i++)
					ret.push_back(ch);
			}
			else
			{
				char big = vm.find(10 * power)->second;
				ret.push_back(ch);
				ret.push_back(big);
			}
			num %= power;
			power /= 10;
		}
		return ret;
	}
};