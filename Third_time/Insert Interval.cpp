/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        int len = intervals.size();
        int i = 0;
        while(i < len && intervals[i].end < newInterval.start)
        {
            ret.push_back(intervals[i]);
            i++;
        }
            
        while(i < len && intervals[i].start <= newInterval.end)
        {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        ret.push_back(newInterval);
        while(i<len)
            ret.push_back(intervals[i++]);
        return ret;
    }
};