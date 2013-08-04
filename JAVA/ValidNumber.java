class Solution {
	public boolean isNumber(String s) {
		// Start typing your Java solution below
		// DO NOT write main() function
		boolean hasNumber = false;
		boolean hasE = false;
		boolean hasDot = false;
		s = s.trim();
		if(s.length() == 0)
			return false;
		for(int i = 0; i < s.length(); i++)
		{
			char ch = s.charAt(i);
			if((ch < '0' || ch > '9') && ch != '.' && ch != 'e' && ch != '+' && ch != '-')
				return false;
			if(ch == 'e')
			{
				if(!hasNumber || hasE || i == s.length() - 1)
					return false;
				else
					hasE = true;
			}
			else if(ch == '.')
			{
				if(hasDot || hasE)
					return false;
				else
					hasDot = true;
			}
			else if(ch == '+' || ch == '-')
			{
				if((i != 0 && s.charAt(i-1) != 'e') || i == s.length()-1)
					return false;
			}
			else
				hasNumber = true;
		}
		if(!hasNumber && hasDot)
			return false;
		return true;
		
	}
}

public class ValidNumber {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
