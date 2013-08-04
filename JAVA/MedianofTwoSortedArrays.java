class Solution {
	int len;
    double medianValueOnArray(int Arr[], int si, boolean isOdd) {
        if (isOdd)
            return Arr[si];
        else {
            return (Arr[si] + Arr[si + 1]) / 2.0;
        }
    }
    double medianValueOnArrays(int A[], int m, int ms, int B[], int n, int ns, boolean isOdd){
        int[] sorted = new int[2];
        for(int i = 0 ; i < 2; ++i) {
            if(ms < m) {
                if (ns < n) {
                    sorted[i] = (A[ms] <= B[ns] ? A[ms++] : B[ns++]);
                } else {
                    sorted[i] = A[ms++];
                }
            } else {
                sorted[i] = B[ns++];
            }
            if (isOdd) {
                return sorted[0];
            }
        }
        return 0.5 * (sorted[0] + sorted[1]);
    }
	public double findMedianSortedArrays(int A[], int B[]) {
		// Start typing your Java solution below
		// DO NOT write main() function
		int m = A.length;
		int n = B.length;
		if (m + n <= 0)
			return 0;
		// find the number at this index from ms and ns
		int target = (m + n - 1) / 2;
		// if isOdd return val[target] is ok
		// else return (val[target] + val[target + 1]) / 2
		boolean isOdd = ((m + n) % 2) == 1;

		int ms = 0;// current start index in A
		int ns = 0;// current start index in B
		while (true) {
			// if A or B is empty just anotherArray[target] is the target
			if (m - ms <= 0) {// A is empty
				return medianValueOnArray(B, ns + target, isOdd);
			} else if (n - ns <= 0) {// B is empty
				return medianValueOnArray(A, ms + target, isOdd);
			}
			// A and B are not empty
			if (target <= 0) {
				return medianValueOnArrays(A, m, ms, B, n, ns, isOdd);
			}
			// divide the numbers smaller than val[target]
			int divideCount = target > 1 ? (target - 2) / 2 : 0;
			int plus = target > 2 ? target % 2 : 0;
			int mm = ms + divideCount;
			if (mm >= m)
				mm = m - 1;
			int nm = ns + divideCount;
			if (nm >= n)
				nm = n - 1;
			if (n - nm >= m - mm)
				nm += plus;
			else
				mm += plus;
			if (A[mm] >= B[nm]) {
				// in this case, the numbers at the beginning of B is
				// impossiblely contain val[target]
				target -= (nm - ns + 1);
				ns = nm + 1;
			} else {
				target -= (mm - ms + 1);
				ms = mm + 1;
			}
		}
	}
}

public class MedianofTwoSortedArrays {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A = { 4, 5 };
		int[] B = { 1, 2, 3 };
		Solution sol = new Solution();
		System.out.println("" + sol.findMedianSortedArrays(A, B));
	}

}
