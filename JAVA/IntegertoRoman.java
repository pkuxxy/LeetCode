class Solution {
	static char[][] roman = {{'I','V'},{'X','L'},{'C','D'},{'M',' '}};
    public String intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int pow = 1;
        int len = 0;
        while(pow * 10 <= num)
        {
        	len++;
        	pow *= 10;
        }
        StringBuilder sb = new StringBuilder();
        while(num > 0)
        {
        	int pos = num / pow;
        	if(pos == 9)
        	{
        		sb.append(roman[len][0]).append(roman[len+1][0]);
        	}
        	else if(pos >= 5)
        	{
        		sb.append(roman[len][1]);
        		int remain = pos - 5;
        		for(int i = 0; i < remain; i++)
        		{
        			sb.append(roman[len][0]);
        		}
        	}
        	else if(pos == 4)
        	{
        		sb.append(roman[len][0]).append(roman[len][1]);
        	}
        	else
        	{
        		for(int i = 0; i < pos; i++)
        		{
        			sb.append(roman[len][0]);
        		}
        	}
        	num -= pos * pow;
        	pow /= 10;
        	len--;
        }
        return sb.toString();  
    }
}
public class IntegertoRoman {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int num = 1999;
		Solution sol = new Solution();
		System.out.println(sol.intToRoman(num));
	}

}
