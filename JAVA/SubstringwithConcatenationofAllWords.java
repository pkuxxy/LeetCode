import java.util.ArrayList;
import java.util.HashMap;

class Solution {
	ArrayList<Integer> ret = new ArrayList<Integer>();
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(S == null || L == null || L.length == 0 || S.length() < L.length*L[0].length())
        {
        	return ret;
        }
        HashMap<String, Integer> wordCountMap = new HashMap<String, Integer>();
        for(int i = 0; i < L.length; i++)
        {
        	if(wordCountMap.containsKey(L[i]))
        		wordCountMap.put(L[i], wordCountMap.get(L[i])+1);
        	else
        		wordCountMap.put(L[i], 1);
        }
        int sLen = S.length();
        int LLen = L.length*L[0].length();
        int wordLen = L[0].length();
        for(int i = 0; sLen - i >= LLen; i++)
        {
        	HashMap<String, Integer> tmp = new HashMap<String, Integer>(wordCountMap);
        	for(int j = 0; j < L.length; j++)
        	{
        		String sub = S.substring(i+j*wordLen, i+(j+1)*wordLen);
        		if(!tmp.containsKey(sub))
        			break;
        		int count = tmp.get(sub);
        		if(count > 1)
        			tmp.put(sub, count-1);
        		else
        			tmp.remove(sub);
        	}
        	if(tmp.isEmpty())
        		ret.add(i);
        }
        return ret;
    }
}
public class SubstringwithConcatenationofAllWords {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
