import java.util.ArrayList;

class Interval {
	int start;
	int end;

	Interval() {
		start = 0;
		end = 0;
	}

	Interval(int s, int e) {
		start = s;
		end = e;
	}
}

class Solution {
	ArrayList<Interval> ret = new ArrayList<Interval>();
	public ArrayList<Interval> insert(ArrayList<Interval> intervals,
			Interval newInterval) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		if(intervals == null)
			return ret;
		Interval insert = new Interval();
		int left = binarySearch(intervals, 0, intervals.size()-1, newInterval.start, true);
		int right = binarySearch(intervals, 0, intervals.size()-1, newInterval.end, false);
		if(left == -1 || right == -1)
		{
			insert = newInterval;
			if(left == -1)
				left = intervals.size();
			else
				right = -1;
		}
		else
		{
			insert.start = Math.min(newInterval.start, intervals.get(left).start);
			insert.end = Math.max(newInterval.end, intervals.get(right).end);
		}
		for(int i = 0; i < left; i++)
		{
			ret.add(intervals.get(i));
		}
		ret.add(insert);
		for(int i = right+1; i < intervals.size(); i++)
			ret.add(intervals.get(i));
		return ret;
	}
	private int binarySearch(ArrayList<Interval> intervals, int left, int right,
			int value, boolean isLeft) {
		if(left > right)
			return -1;
		int mid = (left + right) / 2;
		if(isLeft)
		{
			if(intervals.get(mid).end == value)
				return mid;
			else if(intervals.get(mid).end > value)
			{
				int pos = binarySearch(intervals, left, mid-1, value, isLeft);
				return pos == -1 ? mid : pos;
			}
			else
			{
				return binarySearch(intervals, mid+1, right, value, isLeft);
			}
		}
		else
		{
			if(intervals.get(mid).start == value)
				return mid;
			else if(intervals.get(mid).start < value)
			{
				int pos = binarySearch(intervals, mid+1, right, value, isLeft);
				return pos == -1 ? mid : pos;
			}
			else
				return binarySearch(intervals, left, mid-1, value, isLeft);
		}
	}
}

public class InsertInterval {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Interval> intervals = new ArrayList<Interval>();
		intervals.add(new Interval(1,5));
		Interval newInterval = new Interval(6,8);
		Solution sol = new Solution();
		System.out.println(sol.insert(intervals, newInterval));
	}

}
