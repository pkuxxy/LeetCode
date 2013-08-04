class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == INT_MIN)
        {
             double half = pow(x,n/2);
             return half*half;
        }
        else if(n < 0)
            return 1/pow(x, -n);
        if(n == 0)
            return 1;
        double half = pow(x, n/2);
        if(n%2)
            return x*half*half;
        else
            return half*half;
    }
};