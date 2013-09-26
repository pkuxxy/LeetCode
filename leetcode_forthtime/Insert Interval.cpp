
class Solution {
public:
    int lbs(vector<Interval>& ins, int l, int r, Interval ni)
	{
		if(l > r)
			return -1;
		int mid = l+(r-1)/2;
		if(ni.start == ins[mid].start)
			return mid;
		else if(ni.start < ins[mid].start)
		{
			int pos = lbs(ins, l, mid-1, ni);
			return pos == -1? mid-1:pos;
		}
		else
		{
			int pos = lbs(ins, mid+1, r, ni);
			return pos == -1? mid:pos;
		}
	}
	int rbs(vector<Interval>& ins, int l, int r, Interval ni)
	{
		if(l > r)
			return -1;
		int mid = l+(r-l)/2;
		if(ni.end == ins[mid].end)
			return mid;
		else if(ni.end < ins[mid].end)
		{
			int pos = rbs(ins, l, mid-1, ni);
			return pos == -1 ? mid:pos;
		}
		else
		{
			int pos = rbs(ins, mid+1, r, ni);
			return pos == -1 ? mid+1:pos;
		}
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Interval> ret;
		int len = intervals.size();
		if(!len)
        {
            ret.push_back(newInterval);
            return ret;
        }
			
		int l = lbs(intervals, 0, len-1, newInterval);
		int r = rbs(intervals, 0, len-1, newInterval);
		if(l >= 0 && intervals[l].end >= newInterval.start)
		{
			l--;
		}
		if(r < len && intervals[r].start <= newInterval.end)
		{
			r++;
		}
		newInterval.start = (l+1 >= len)?newInterval.start : min(newInterval.start, intervals[l+1].start);
		newInterval.end = (r-1 < 0)?newInterval.end : max(newInterval.end, intervals[r-1].end);
		for(int i = 0; i <= l; i++)
		{
			ret.push_back(intervals[i]);
		}
		ret.push_back(newInterval);
		for(int i = r; i < len; i++)
			ret.push_back(intervals[i]);
		return ret;
	}
};