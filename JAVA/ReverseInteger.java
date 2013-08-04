class Solution {
	public int reverse(int x) {
		// Start typing your Java solution below
		// DO NOT write main() function
		String original = String.valueOf(x);
		int start = 0;
		if(original.charAt(0) == '-')
			start = 1;
		String rev = reverseStr(original.substring(start));
		StringBuilder ret = new StringBuilder(original.substring(0, start));
		int i = 0;
		while(i < rev.length() && rev.charAt(i) == '0')
			i++;
		if(i >= rev.length())
			ret.append('0');
		else
			ret.append(rev.substring(i));
		return Integer.parseInt(ret.toString());
	}

	private String reverseStr(String str) {
		StringBuilder sb = new StringBuilder();
		int len = str.length();
		for(int i = 0; i < len; i++)
		{
			sb.append(str.charAt(len - i - 1));
		}
		return sb.toString();
	}
}

public class ReverseInteger {

	/**
	 * @param args
	 */

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
