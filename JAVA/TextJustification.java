import java.util.ArrayList;

class Solution {
	ArrayList<String> ret = new ArrayList<String>();
    public ArrayList<String> fullJustify(String[] words, int L) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ret.clear();
        if(words == null || words.length == 0)
        	return ret;
        int len = words[0].length();
        int whiteCount = 0;
        ArrayList<Integer> index = new ArrayList<Integer>();
        ArrayList<Integer> lengh = new ArrayList<Integer>();
        for(int i = 1 ;i < words.length; i++)
        {
        	int curLen = len;
        	curLen++;
        	curLen += words[i].length();
        	if(curLen > L)
        	{
        		index.add(i);
        		lengh.add(len-whiteCount);
        		len = words[i].length();
        		whiteCount = 0;
        	}
        	else
        	{
        		len = curLen;
        		whiteCount++;
        	}
        }
		index.add(words.length);
		lengh.add(len-whiteCount);
        int start = 0;
        StringBuilder sb = null;
        for(int i = 0; i < index.size(); i++)
        {
        	int end = index.get(i);
        	sb = new StringBuilder();
        	sb.append(words[start]);
        	int wordCount = end-start;
        	whiteCount = L-lengh.get(i);
        	if(wordCount == 1 || i == index.size()-1)
        	{
        		for(int j = start+1; j < end; j++)
        		{
        			sb.append(' ');
        			sb.append(words[j]);
        		}
        		for(int k = 0; k < whiteCount - wordCount+1; k++)
        		{
        			sb.append(' ');
        		}
        	}
        	else
        	{
        		int left = whiteCount % (wordCount-1);
        		int interval = whiteCount / (wordCount-1);
            	for(int j = start+1; j <= start+left; j++)
            	{
            		for(int k = 0; k < interval+1; k++)
            		{
            			sb.append(' ');
            		}
            		sb.append(words[j]);
            	}
            	for(int j = start+(left == 0?1:left+1); j < end; j++)
            	{
            		for(int k = 0; k < interval; k++)
            		{
            			sb.append(' ');
            		}
            		sb.append(words[j]);
            	}
        	}
        	ret.add(sb.toString());
        	start = end;
        }
        return ret;
    }
}
public class TextJustification {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String[] words = {"Here","is","an","example","of","text","justification."};
		int L = 16;
		Solution sol = new Solution();
		System.out.println(sol.fullJustify(words, L));
	}

}
