import java.util.ArrayList;

class Solution {
    public String getPermutation(int n, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(k < 1 || n < 1)
        	return "";
        k--;
        int i = 0;
        ArrayList<Character> can = new ArrayList<Character>();
        char[] ret = new char[n];
        for(; i < n ;i++)
        {
        	can.add((char) (i+'1'));
        }
        i = 0;
        while(i < n)
        {
        	int f = getFactorial(n - i - 1);
        	int p = k / f;
        	ret[i++] = can.get(p);
        	can.remove(p);
        	k = k % f;
        }
        return new String(ret);
    }

	private int getFactorial(int n) {
		if(n == 0)
			return 1;
		int f = n;
		while(--n > 0)
			f *= n;
		return f;
	}
}
public class PermutationSequence {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
