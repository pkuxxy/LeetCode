class Solution {
    public String strStr(String haystack, String needle) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	if(needle.length() == 0)
    		return haystack;
    	int len1 = haystack.length();
    	int len2 = needle.length();
        int[] next= new int[len2];
        int i = 0;
        int j  = 0;
        getNext(needle,next);
        
        while(i < len1 && j < needle.length())
        {
        	if(j == -1 || haystack.charAt(i) == needle.charAt(j))
        	{
        		i++;
        		j++;
        	}
        	else
        		j = next[j];
        	if(j == needle.length())
        		return haystack.substring(i-j);
        }
        return null;
    }

	private void getNext(String needle, int[] next) {
	    int j,k;
	    next[0]=-1;
	    j=0;
	    k=-1;
	    while(j<needle.length()-1)
	    {
	        if( k==-1 ||needle.charAt(j) == needle.charAt(k))    //匹配的情况下,p[j]==p[k]
	        {
	            j++;
	            k++;
	            next[j]=k;
	        }
	        else                   //p[j]!=p[k]
	            k=next[k];
	    }
	}
}
public class ImplementStrStr {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String haystack = "";
		String needle = "a";
		Solution sol = new Solution();
		System.out.println(sol.strStr(haystack, needle));
	}

}
