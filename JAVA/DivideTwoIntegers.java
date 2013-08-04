class Solution {
    public int divide(int dividend, int divisor) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	int sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        	sign = -1;
        long a = dividend;
        long b = divisor;
        if(a < 0)
        	a = Math.abs(a);
        if(b < 0)
        	b = Math.abs(b);
        long[] f = new long[100];
        f[0] = b;
        int size = 1;
        while(f[size-1] < a)
        {
        	f[size] = f[size-1] + f[size-1];
        	size++;
        }
        int ret = 0;
        while(a > 0)
        {
        	int pos = bsearch(f, 0, size-1, a);
        	if(pos == -1)
        		break;
        	ret |= 1<<pos;
        	a -= f[pos];
        }
        return ret*sign;
    }

	private int bsearch(long[] f, int start, int end, long num) {
		if(start > end)
			return -1;
		int mid = (start + end) / 2;
		if(f[mid] == num)
			return mid;
		else if(f[mid] < num)
		{
			int pos = bsearch(f, mid+1, end, num);
			if(pos == -1)
				return mid;
			else
				return pos;
		}
		else
			return bsearch(f, start, mid-1, num);
	}
}
public class DivideTwoIntegers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
