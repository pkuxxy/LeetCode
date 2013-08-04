import java.util.Arrays;
import java.util.Comparator;

class Solution {
	static class LengthComparator implements Comparator<String> {

		@Override
		public int compare(String s1, String s2) {
			if (s1.length() == s2.length())
				return s1.compareTo(s2);
			return s1.length() - s2.length();
		}

	}

	public String longestCommonPrefix(String[] strs) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if (strs == null || strs.length == 0)
			return "";
		Arrays.sort(strs, new LengthComparator());
		String shortest = strs[0];
		StringBuilder lcp = new StringBuilder();

		for (int i = 0; i < shortest.length(); i++) {
			for (int j = 1; j < strs.length; j++) {
				if(shortest.charAt(i) != strs[j].charAt(i))
				{
					return lcp.toString();
				}
			}
			lcp.append(shortest.charAt(i));
		}
		return lcp.toString();
	}
}

public class LongestCommonPrefix {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Solution sol = new Solution();
		String[] strs = {"flower","flow","flight"};
		System.out.println(sol.longestCommonPrefix(strs));

	}

}
