class Solution {
    public String addBinary(String a, String b) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(a == null || b == null)
    		return null;
        a = reverse(a);
        b = reverse(b);
        StringBuilder sb = new StringBuilder();
        int len = Math.min(a.length(), b.length());
        int sum = 0;
        int carry = 0;
        int i = 0;
        for(; i < len; i++)
        {
        	sum = a.charAt(i)-'0' + b.charAt(i)-'0' + carry;
        	carry = sum/2;
        	sum %= 2;
        	sb.append(String.valueOf(sum));
        }
        while(i < a.length())
        {
        	sum = a.charAt(i)-'0' + carry;
        	carry = sum/2;
        	sum %= 2;
        	sb.append(String.valueOf(sum));
        	i++;
        }
        while(i < b.length())
        {
        	sum = b.charAt(i)-'0' + carry;
        	carry = sum/2;
        	sum %= 2;
        	sb.append(String.valueOf(sum));
        	i++;
        }
        if(carry == 1)
        	sb.append('1');
        return reverse(sb.toString());
    }

	private String reverse(String s) {
		StringBuilder sb = new StringBuilder();
		int len = s.length();
		for(int i = len - 1; i >= 0; i--)
		{
			sb.append(s.charAt(i));
		}
		return sb.toString();
	}
}
public class AddBinary {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
