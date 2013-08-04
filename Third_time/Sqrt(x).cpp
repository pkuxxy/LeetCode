class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(x < 0)
			return -1;
		long long x2 = x;
        long long l = 0;
        long long r = x2;
        while(l <= r)
        {
            long long mid = l+(r-l)/2;
            //long long sq = mid*mid;
            if(mid*mid <= x2 && (mid+1)*(mid+1) > x2 )
                return mid;
            else if(mid*mid <= x2)
                l = mid+1;
            else
                r = mid-1;
        }
        return r;
    }
};