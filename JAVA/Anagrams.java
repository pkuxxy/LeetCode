import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;

class Solution {

	public ArrayList<String> anagrams(String[] strs) {
		// Start typing your Java solution below
		// DO NOT write main() function
		ArrayList<String> ret = new ArrayList<String>();
		if (strs == null || strs.length == 0) {
			return ret;
		}
		HashMap<String, LinkedList<String>> listMap = new HashMap<String, LinkedList<String>>();
		for (String str : strs) {
			char[] chs = str.toCharArray();
			Arrays.sort(chs);
			String ordered = new String(chs);
			if (listMap.containsKey(ordered)) {
				listMap.get(ordered).add(str);
			} else {
				LinkedList<String> list = new LinkedList<String>();
				list.add(str);
				listMap.put(ordered, list);
			}
		}
		for (LinkedList<String> list : listMap.values()) {
			if (list.size() > 1) {
				ret.addAll(list);
			}
		}
		return ret;
	}
}

public class Anagrams {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] strs = {"and","dan"};
		Solution sol = new Solution();
		System.out.println(sol.anagrams(strs));
	}

}
