import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
	public int ladderLength(String start, String end, HashSet<String> dict) {
		// Start typing your Java solution below
		// DO NOT write main() function
		Queue<String> queue = new LinkedList<String>();
		HashSet<String> visited = new HashSet<String>();
		queue.add(start);
		int len = start.length();
		int level = 2;
		int curLevel = 1;
		int nextLevel = 0;
		visited.add(start);
		while (!queue.isEmpty()) {
			String cur = queue.poll();
			curLevel--;
			visited.add(cur);
			char[] array = cur.toCharArray();
			for (int i = 0; i < len; i++) {
				char chtmp = array[i];
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if(cur.charAt(i) == ch)
						continue;
					array[i] = ch;
					String tmp = new String(array);
					if(tmp.equals(end))
						return level;
					if(dict.contains(tmp) && !visited.contains(tmp))
					{
						queue.add(tmp);
						visited.add(tmp);
						nextLevel++;
					}
				}
				array[i] = chtmp;
			}

			if (curLevel == 0) {
				curLevel = nextLevel;
				level++;
				nextLevel = 0;
			}
		}
		return 0;
	}
}

public class WordLadder {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
