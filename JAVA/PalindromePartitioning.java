import java.util.ArrayList;

class Solution {
	ArrayList<ArrayList<String>> ret = new ArrayList<ArrayList<String>>();

	public ArrayList<ArrayList<String>> partition(String s) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ret.clear();
		if (s == null || s.length() == 0)
			return ret;
		ArrayList<String> list = new ArrayList<String>();
		solve(0, s.length(), s, list);
		return ret;
	}

	private void solve(int index, int len, String s, ArrayList<String> list) {
		if (index == len) {
			ret.add(new ArrayList<String>(list));
			return;
		}
		for (int i = index+1; i <= len; i++) {
			String sub = s.substring(index, i);
			if (isPalindrome(sub)) {
				list.add(sub);
				solve(i, len, s, list);
				list.remove(list.size() - 1);
			}
		}
	}

	private boolean isPalindrome(String s) {
		if (s == null)
			return false;
		int mid = s.length() / 2;
		for (int i = 0; i < mid; i++) {
			if (s.charAt(i) != s.charAt(s.length() - i -1))
				return false;
		}
		return true;
	}
}

public class PalindromePartitioning {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s = "abbab";
		Solution sol = new Solution();
		System.out.println(sol.partition(s));
	}

}
