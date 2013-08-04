import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

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
	static class EndComparator implements Comparator<Interval>
	{

		@Override
		public int compare(Interval o1, Interval o2) {
			if(o1.start == o2.start)
				return o1.end - o2.end;
			return o1.start - o2.start;
		}
		
	}
	public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
		ret.clear();
		if(intervals == null || intervals.size() == 0)
			return ret;
		Interval[] arrays = intervals.toArray(new Interval[0]);
		Arrays.sort(arrays, new EndComparator());
		int start = arrays[0].start;
		int end = arrays[0].end;
		for(int i = 1; i < arrays.length; i++)
		{
			if(arrays[i].start <=  end)
			{
				if(arrays[i].end > end)
					end = arrays[i].end;
			}
			else
			{
				ret.add(new Interval(start,end));
				start = arrays[i].start;
				end = arrays[i].end;
			}
		}
		ret.add(new Interval(start, end));
		return ret;
	}
}

public class MergeIntervals {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Interval> list = new ArrayList<Interval>();
		list.add(new Interval(1,4));
		list.add(new Interval(2,5));
		Solution sol = new Solution();
		System.out.println(sol.merge(list));
	}

}
