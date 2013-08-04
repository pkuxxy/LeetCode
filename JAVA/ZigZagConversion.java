class Solution {
    public String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(nRows <= 1 || s.length() <= nRows)
    		return s;
    	StringBuilder sb = new StringBuilder();
    	int zigSize = 2 * nRows -2;
    	int len = s.length();
    	for(int row = 0; row < nRows; row++)
    	{
    		int interval = zigSize - 2 * row;
    		int index = row;
    		while(index < len)
    		{
    			sb.append(s.charAt(index));
    			if(row != 0 && row != nRows-1 && index + interval < len)
    				sb.append(s.charAt(index+interval));
    			index += zigSize;
    		}
    	}
    	return sb.toString();
    }
}
public class ZigZagConversion {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
