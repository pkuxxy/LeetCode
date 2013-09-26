// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include<vector>
using namespace std;
int solutionNum(vector<int>& nums, int target)
{
    int count = 0;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for(int i = 0; i < len; i++)
    {
        int sum1 = target - nums[i];
        int j = i+1;
        int k = len-1;
        while(j < k)
        {
            int sum2 = nums[j] + nums[k];
            if(sum2 > sum1)
                k--;
            else
            {
                while(j < k && sum2 <= sum1)
                {
                    j++;
                    sum2 = nums[j]+nums[k];
                }
                count += j-i-1;
            }
        }
    }
    return count;
}
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(11);
    cout<<solutionNum(nums, 10);
    return 0;
}