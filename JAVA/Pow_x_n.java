
class Solution {
    public double pow(double x, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(n == 0)
    		return 1;
    	if(x == 0.0)
    		return 0;
    	if(x == 1.0)
    		return 1;
    	if(x == -1.0)
    	{
    		if(n % 2 == 0)
    			return 1;
    		return -1;
    	}
    	if(n < 0)
    		return 1/pow(x, -n);

    	double sum = 1;
    	double base = x;
    	while(n > 0)
    	{
    		if((n & 1) == 1)
    			sum *= base;
    		n >>= 1;
    		base *= base;
    	}
    	return sum;		
    }
}
public class Pow_x_n {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
