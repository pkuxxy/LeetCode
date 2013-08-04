#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval& o1, const Interval o2)
{
	if(o1.start == o2.start)
		return o2.end > o1.end;
	return o2.start > o1.start;
}
class Solution {
public:

	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Interval> ret;
		int len = intervals.size();
		if(!len)
			return ret;
		sort(intervals.begin(), intervals.end(), cmp);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for(int i = 1; i < len; i++)
		{
			if(intervals[i].start <= end)
			{
				end = max(end,intervals[i].end);
			}
			else
			{
				ret.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
		}
		ret.push_back(Interval(start, end));
		return ret;
	}
};
