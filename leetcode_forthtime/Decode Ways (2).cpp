class Solution {
public:
    bool isValid(string s, int st, int end)
    {
        if(st > end || end - st+1 >= 3 || s[st] == '0')
            return false;
        int sum = 0;
        for(int i = st; i <= end; i++)
        {
            sum *= 10;
            sum += s[i] - '0';
        }
        return 1 <= sum && sum <= 26;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return 0;
        vector<int> f(len+1, 0);
        f[0]=1;
        if(isValid(s, 0,0))
            f[1] = 1;
        for(int i = 2; i <= len; i++)
        {
            if(isValid(s, i-1, i-1))
                f[i] += f[i-1];
            if(isValid(s, i-2, i-1))
                f[i] += f[i-2];
        }
        return f[len];
    }
};