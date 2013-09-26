#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<ctime>
using namespace std;
unsigned int countLowerOrEqualThan(vector<int>& nums, int r)
{
	unsigned int len = nums.size();
	int s = 0;
	int e = len-1;
	while(s <= e)
	{
		int mid = s+(e-s)/2;
		if(nums[mid] <= r && (mid+1 == len || nums[mid+1] > r))
			return mid+1;
		else if(nums[mid] > r)
			e = mid-1;
		else
			s = mid+1;
	}
	return 0;
}
int getRandomNotExistValue(vector<int>& nums)
{
	unsigned int len = nums.size();
	if(len == (~0))
		return INT_MIN;
	vector<int> clone(nums);
	for(int i = 0; i < len; i++)
	{
		clone[i] -= i;
	}
	srand(time(0));
	unsigned int r = rand()%((~0)-len);
	r = 0;
	return r + countLowerOrEqualThan(clone, r);
}

int main() {
	int a[]={4, 6, 9};
	vector<int> nums(a, a+3);
	cout<<getRandomNotExistValue(nums)<<endl;;
	getchar();
	return 0;
}