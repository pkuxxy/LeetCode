import java.util.ArrayList;

class Solution {
	ArrayList<String> ret = new ArrayList<String>();
    public ArrayList<String> restoreIpAddresses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ret.clear();
        if(s == null || s.length() <= 3 || s.length() > 12)
        	return ret;
        ArrayList<Integer> list = new ArrayList<Integer>();
        dfs(0, s.length(), s, list);
        return ret;
    }
	private void dfs(int index, int len, String s, ArrayList<Integer> list) {
		if(index == len)
		{
			if(list.size() != 4)
				return;
			StringBuilder sb = new StringBuilder();
			int i = 0;
			for(; i < 3; i++)
			{
				sb.append(String.valueOf(list.get(i))).append('.');
			}
			sb.append(String.valueOf(list.get(i)));
			ret.add(sb.toString());
			return;
		}
		for(int i = 1; i <= 3 && index+i <= len; i++)
		{
			String str = s.substring(index, index+i);
			if(i > 1 && str.charAt(0) == '0')
				continue;
			int cur = Integer.parseInt(str);
			if(cur > 255)
				continue;
			list.add(cur);
			dfs(index+i, len, s, list);
			list.remove(list.size()-1);
		}
	}
    
}
public class RestoreIPAddresses {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
