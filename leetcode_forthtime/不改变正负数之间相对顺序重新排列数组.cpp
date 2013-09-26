#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
void merge(vector<int>& nums, int s1, int e1, int s2, int e2)
{
	int i = -1;
	int j = -1;
	for(int k = s1; k <= e1; k++)
	{
		if(nums[k] > 0)
		{
			i = k;
			break;
		}
	}
	if(i == -1)
		return;
	for(int k = s2; k <= e2; k++)
	{
		if(nums[k] > 0)
		{
			j = k-1;
			break;
		}
	}
	if(j == -1)
		j = e2;
	else if(j == s2-1)
		return;
	reverse(nums.begin()+i, nums.begin()+e1+1);
	reverse(nums.begin()+e1+1, nums.begin()+j+1);
	reverse(nums.begin()+i, nums.begin()+j+1);
}
void stableMerge(vector<int>& nums)
{
	int len = nums.size();
	if(!len)
		return;
	for(int i = 1; i <= len; i *= 2)
	{
		for(int j = 0; j < len-i; j += 2*i)
		{
			merge(nums, j, j+i-1, j+i,min(len-1, j+2*i-1));
		}
	}
}
int main() {
	int a[]={3 ,4, -1, -3, 5, 2, -7, 6, 1};
	vector<int> num(a, a+9);
	stableMerge(num);
	getchar();
	return 0;
}