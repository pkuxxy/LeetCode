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

class Solution {
public:
	int bs(vector<Interval> &intervals, int s, int e, int target)
	{
		if(s > e)
			return -1;
		int mid = (s+e)/2;
		int data = intervals[mid].start;
		if(data == target)
			return mid;
		else if(data < target)
		{
			int pos = bs(intervals, mid+1, e, target);
			return pos == -1 ? e : pos;
		}
		else
		{
			int pos = bs(intervals, s, mid-1, target);
			return pos == -1 ? s-1 : pos;
		}
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Interval> ret;
		int len = intervals.size();
		int sindex = bs(intervals, 0, len-1, newInterval.start);
		int eindex = bs(intervals, 0, len-1, newInterval.end);
		if(sindex == -1)
		{
			if(eindex == -1)
			{
				ret.push_back(newInterval);
				for(int i = 0; i < len; i++)
				{
					ret.push_back(intervals[i]);
				}
			}
			else
			{
				if(intervals[eindex].end <= newInterval.end)
					ret.push_back(newInterval);
				else
					ret.push_back(Interval(newInterval.start, intervals[eindex].end));
				for(int i = eindex+1; i < len; i++)
					ret.push_back(intervals[i]);
			}
		}
		else
		{
			if(intervals[sindex].end >= newInterval.start)
			{
				newInterval.start = intervals[sindex].start;
				sindex--;
			}
			if(intervals[eindex].end >= newInterval.end)
			{
				newInterval.end = intervals[eindex].end;
			}
			for(int i = 0; i <= sindex; i++)
			{
				ret.push_back(intervals[i]);
			}
			ret.push_back(newInterval);
			for(int i = eindex+1; i < len; i++)
			{
				ret.push_back(intervals[i]);
			}
		}
		return ret;
	}
};
int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,5));
	intervals.push_back(Interval(6,8));
	Interval newInterval(5,6);
	Solution sol;
	sol.insert(intervals, newInterval);
	getchar();
}