class Solution {
public:
    int fib(int n)
    {
        int ret = 1;
        for(int i = 1; i <= n; i++)
        {
            ret *= i;
        }
        return ret;
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1 || k < 1)
            return "";
        string orig;
        string ret;
        for(int i = 0; i < n; i++)
        {
            orig.push_back('1'+i);
        }
        n--;
        k--
        while(n >= 0)
        {
            int f = fib(n);
            int p = k/f;
            ret.push_back(orig[p]);
            orig.erase(orig.begin()+p);
            k %= f;
            n--;
        }
        return ret;
    }
};