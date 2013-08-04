class Solution {
    public String multiply(String num1, String num2) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(num1 == null || num2 == null)
    		return null;
    	int len1 = num1.length();
    	int len2 = num2.length();
    	int[] num = new int[len1+len2];
    	for(int i = 0; i < len1+len2; i++)
    	{
    		num[i] = 0;
    	}
    	StringBuilder sb = new StringBuilder(num1);
    	num1 = sb.reverse().toString();
    	sb = new StringBuilder(num2);
    	num2 = sb.reverse().toString();
    	for(int i = 0; i < len1; i++)
    	{
    		for(int j = 0; j < len2; j++)
    		{
    			num[i+j] += (num1.charAt(i)-'0') * (num2.charAt(j)-'0');
    			if(num[i+j] > 9)
    			{
    				num[i+j+1] += num[i+j]/10;
    				num[i+j] %= 10;
    			}
    		}
    	}
    	int start = len1+len2-1;
    	while(start >= 0 && num[start] == 0)
    		start--;
    	if(start < 0)
    		return "0";
    	sb = new StringBuilder();
    	for(int i = start; i >= 0; i--)
    	{
    		sb.append(String.valueOf(num[i]));
    	}
    	return sb.toString();
    		
    }
}
public class MultiplyStrings {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String num1 = "1";
		String num2 = "2";
		Solution sol = new Solution();
		System.out.println(sol.multiply(num1, num2));
	}

}
