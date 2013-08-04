#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
class Node
{
public:
	int index;
	int val;
	Node(int i, int v)
	{
		index = i;
		val = v;
	}
};
bool compare(Node n1, Node n2)
{
	return n1.val < n2.val;
}
class Solution {
public:
	
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<Node> nodes;
		for(int i = 0; i < numbers.size(); i++)
		{
			nodes.push_back(Node(i+1, numbers[i]));
		}

		sort(nodes.begin(), nodes.end(),compare);
		
		int i = 0;
		int j = nodes.size()-1;
		vector<int> ret;
		while(i < j)
		{
			int sum = nodes[i].val + nodes[j].val;
			if(sum == target)
			{
				ret.push_back(min(nodes[i].index, nodes[j].index));
				ret.push_back(max(nodes[i].index, nodes[j].index));
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
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(75);
	nums.push_back(25);
	Solution sol;
	sol.twoSum(nums, 100);
}