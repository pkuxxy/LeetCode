#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int val;
	int index;
	Node(){}
	Node(int v, int ind)
	{
		val = v;
		index = ind;
	}
};
bool cmp(const Node& n1, const Node& n2)
{
	return n1.val < n2.val;
}
class Solution {
public:

	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ret;
		int len = numbers.size();
		if(len < 2)
			return ret;
		vector<Node> m(len);
		for(int i = 0; i < len; i++)
		{
			m[i] = Node(numbers[i],i+1);
		}
		sort(m.begin(), m.end(),cmp);
		int i = 0;
		int j = len-1;
		while(i < j)
		{
			int sum = m[i].val+m[j].val;
			if(sum == target)
			{
				ret.push_back(min(m[i].index, m[j].index));
				ret.push_back(max(m[i].index, m[j].index));
				return ret;
			}
			else if(sum < target)
				i++;
			else
				j--;
		}
		return ret;
	}
};
int main()
{
	int a[] = {9, 8, 7,6,5};
	vector<int> num(a, a+5);
	Solution sol;
	sol.twoSum(num, 14);
	getchar();
}