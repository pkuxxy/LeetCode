class Solution {
    public int sqrt(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        double ans = x;
        while(Math.abs(ans*ans - x) > 0.001)
        {
        	ans = (ans+x/ans)/2;
        }
        return (int)ans;
    }
}
public class Sqrt_x_ {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x = 2147395599;
		Solution sol = new Solution();
		System.out.println(""+sol.sqrt(x));
	}

}
