class Solution {
    public boolean isPalindrome(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(x < 0)
        	return false;
        int base = 1;
        while(x/base >= 10)
        	base *= 10;
        while(x > 0)
        {
        	int left = x / base;
        	int right = x % 10;
        	if(left != right)
        		return false;
        	x -= left * base;
        	base /= 100;
        	x /= 10;
        }
        return true;
    }
}
public class PalindromeNumber {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
