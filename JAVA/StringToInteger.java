class Solution {
	public boolean isDigit(char ch) {
		return ch >= '0' && ch <= '9';
	}

	public int atoi(String str) {
		// Start typing your Java solution below
		// DO NOT write main() function
		if (null == str || str.length() == 0)
			return 0;
		int i = 0;
		while (i < str.length() && str.charAt(i) == ' ')
			i++;
		if (i == str.length())
			return 0;
		StringBuilder digits = new StringBuilder();
		char first = str.charAt(i);
		if (first == '+' || first == '-')
			i++;
		else if (!isDigit(first))
			return 0;
		while (i < str.length() && isDigit(str.charAt(i))) {
			digits.append(str.charAt(i));
			i++;
		}
		if (digits.length() == 0)
			return 0;

		return  StringToInt(digits.toString(),first);
	}

	private int StringToInt(String s, char sign) {
		if(s.length() > 10)
			return sign == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			sum *= 10;
			sum += s.charAt(i) - '0';
			if(sign != '-' && sum < 0)
				return Integer.MAX_VALUE;
			else if(sum < 0)
				return Integer.MIN_VALUE;
		}
		return sign == '-' ? -sum : sum;
	}
}

public class StringToInteger {
	public static void main(String[] args)
	{
		Solution sol = new Solution();
		System.out.println(""+sol.atoi("    10522545459"));
	}
}
