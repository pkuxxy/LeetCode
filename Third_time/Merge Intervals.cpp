class Solution {
public:
    struct cmp
	{
		bool operator()(const Interval& a, const Interval& b)
		{
			if(a.start == b.start)
				return a.end < b.end;
			return a.start < b.start;
		}
	};
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ret;
		int len = intervals.size();
		if(!len)
			return ret;
		sort(intervals.begin(), intervals.end(), cmp());
		Interval tmp = intervals[0];
		for(int i = 1; i < len; i++)
		{
			if(tmp.end >= intervals[i].start)
				tmp.end = max(tmp.end, intervals[i].end);
			else
			{
				ret.push_back(tmp);
				tmp = intervals[i];
			}
		}
		ret.push_back(tmp);
		return ret;
	}
};