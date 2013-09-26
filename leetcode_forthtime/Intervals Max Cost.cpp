// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <algorithm>
#include<math.h>
#include <vector>
using namespace std;
struct Interval
{
	int st;
	int et;
	int cost;
	Interval(int s, int e, int c)
	{
		st = s;
		et = e;
		cost = c;
	}
};
bool cmp(const Interval& o1, const Interval& o2)
{
	if(o1.et == o2.et)
		return o1.st < o2.st;
	return o1.et < o2.et;
}
int bs(vector<Interval>& intervals, int l, int r, int target)
{
	if(l > r)
		return -1;
	int mid = l+(r-l)/2;
	if(intervals[mid].et >= target)
	{
		int pos = bs(intervals, l, mid-1, target);
		return pos == -1 ? l-1:pos;
	}
	else
	{
		int pos = bs(intervals, mid+1, r, target);
		return pos == -1 ?  r : pos;
	}
}
int getMaxCost(vector<Interval>& intervals)
{
	int len = intervals.size();
	sort(intervals.begin(), intervals.end(), cmp);
	vector<int> dp(len+1, 0);
	for(int i = 1; i <= len; i++)
	{
		int before = bs(intervals, 0, i-1, intervals[i-1].st);
		dp[i] = max(dp[i-1], dp[before+1]+intervals[i-1].cost);
	}
	int maxv = INT_MIN;
	for(int i = 0; i <= len; i++)
	{
		maxv = max(maxv, dp[i]);
	}
	return maxv;
}
int main() {
    vector<Interval> ins;
	ins.push_back(Interval(0,1,1));
	ins.push_back(Interval(2,3,2));
	ins.push_back(Interval(3,4,3));
	cout<<getMaxCost(ins)<<endl;
	getchar();
	return 0;
}