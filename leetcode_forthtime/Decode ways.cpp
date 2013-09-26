class Solution {
public:
    bool iscode(string& s, int l, int r)
    {
        if(l > r || r-l+1 >= 3 || s[l] == '0')
            return false;
        int sum = 0;
        for(int i = l; i <= r; i++)
            sum = sum*10+s[i]-'0';
        return sum >= 1 && sum <= 26;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return 0;
        vector<int> f(len+1, 0);
        f[0] = 1;
        if(iscode(s, 0, 0))
            f[1] = 1;
        for(int i = 2; i <= len; i++)
        {
            if(iscode(s, i-1, i-1))
                f[i] += f[i-1];
            if(iscode(s, i-2, i-1))
                f[i] += f[i-2];
        }
        return f[len];
    }
};