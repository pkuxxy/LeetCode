class Solution {
	public boolean isMatch(String s, String p) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if (p.length() == 0)
			return s.length() == 0;
		if (s.length() == 0) {
			int i = 0;
			while (i < p.length() && p.charAt(i) == '*')
				i++;
			return i == p.length();
		}
		int i = 0;
		int j = 0;
		int indexi = 0;
		int indexj = 0;
		boolean star = false;
		while (i < s.length()) {
			if (j == p.length()) {
				if (star)
					indexi++;
				else
					return false;
				i = indexi;
				j = indexj;
			} else if (p.charAt(j) == '*') {
				star = true;
				while (j < p.length() && p.charAt(j) == '*')
					j++;
				if (j == p.length())
					return true;
				indexi = i;
				indexj = j;
			} else if (p.charAt(j) == s.charAt(i) || p.charAt(j) == '?') {
				i++;
				j++;
			}
			else
			{
				if(star)
					indexi++;
				else
					return false;
				i = indexi;
				j = indexj;
			}
		}
		while(j < p.length() && p.charAt(j) == '*')
			j++;
		return j == p.length();
	}
}

public class WildcardMatching_iterative {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
