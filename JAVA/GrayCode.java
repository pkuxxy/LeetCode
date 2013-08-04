import java.util.ArrayList;

class Solution {
    public ArrayList<Integer> grayCode(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ArrayList<Integer> ret = new ArrayList<Integer>();
    	int size = 1 << n;
    	for(int i = 0; i < size; i++)
    	{
    		ret.add(i^(i>>1));
    	}
    	return ret;
    }
}
public class GrayCode {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
