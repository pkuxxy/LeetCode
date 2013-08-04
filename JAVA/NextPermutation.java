
class Solution {
    public void nextPermutation(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(num == null || num.length == 0)
        	return;
        int pos1 = num.length-1;
        while(pos1 >= 1 && num[pos1] <= num[pos1-1])
        {
        	pos1--;
        }
        if(pos1 == 0)
        {
        	for(int i = 0; i < num.length/2; i++)
        	{
        		int t = num[i];
        		num[i] = num[num.length-i-1];
        		num[num.length-1-i] = t;
        	}
        	return;
       	}
        pos1--;
        int pos2 = num.length-1;
        while(pos2 > pos1 && num[pos2] <= num[pos1])
        	pos2--;
        int t = num[pos1];
        num[pos1] = num[pos2];
        num[pos2] = t;
        for(int i = pos1+1; i < (num.length + pos1 + 1)/2; i++)
        {
    		t = num[i];
    		num[i] = num[num.length-i + pos1];
    		num[num.length-i+pos1] = t;
        }
    }
}
public class NextPermutation {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
