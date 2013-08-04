import java.util.ArrayList;

class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(triangle == null || triangle.size() == 0)
        	return 0;
        int len = triangle.size();
        if(len == 1)
        	return triangle.get(0).get(0);
        int[] pre = new int[len];
        int[] cur = new int[len];
        pre[0] = triangle.get(0).get(0);
        for(int i = 1; i < triangle.size(); i++)
        {
        	ArrayList<Integer> list = triangle.get(i);
        	for(int j = 0; j < i+1; j++)
        	{
        		if(j == 0)
        			cur[j] = pre[j]+list.get(j);
        		else if(j < i)
        			cur[j] = list.get(j) + Math.min(pre[j-1], pre[j]);
        		else
        			cur[j] = pre[j-1] + list.get(j);
        	}
        	pre = cur.clone();
        }
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < cur.length; i++)
        {
        	if(min > cur[i])
        		min = cur[i];
        }
        return min;
    }
}
public class Triangle {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(-1);
		ArrayList<ArrayList<Integer>> tri = new ArrayList<ArrayList<Integer>>();
		tri.add(new ArrayList<Integer>(list));
		list.clear();
		list.add(2);
		list.add(3);
		tri.add(new ArrayList<Integer>(list));
		list.clear();
		list.add(1);
		list.add(-1);
		list.add(-3);
		tri.add(list);
		Solution sol = new Solution();
		System.out.println(""+sol.minimumTotal(tri));
	}

}
