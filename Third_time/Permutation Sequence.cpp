class Solution {
public:
    int getf(int n)
    {
        if(n == 0)
            return 1;
        int f = n;
        while(--n)
            f *= n;
        return f;
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1 || k < 1)
            return "";
        k--;
        string ret;
        string orig;
        int i = 0;
        for(; i < n; i++)
        {
            orig.push_back('1'+i);
        }
        i = n-1;
        while(i>=0)
        {
            int f = getf(i);
            int p = k/f;
            ret.push_back(orig[p]);
            orig.erase(orig.begin()+p);
            k %= f;
            i--;
        }
        return ret;
    }
};