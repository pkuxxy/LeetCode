class Solution {
public:
    string prepro(string s)
    {
        string ret;
        ret.push_back('^');
        for(int i = 0; i < s.size(); i++)
        {
            ret.push_back('#');
            ret.push_back(s[i]);
        }
		ret += "#$";
        return ret;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string t = prepro(s);
        int len = t.size();
        vector<int> p(len, 0);
        int c = 0;
        int r = 0;
        for(int i = 1; i < len-1; i++)
        {
            int mirror = 2*c-i;
            p[i] = (r>i)?min(r-i, p[mirror]):0;
            while(t[i+1+p[i]] == t[i-1-p[i]])
                p[i]++;
            if(i+p[i] > r)
            {
                c = i;
                r = i+p[i];
            }
        }
        int center = 0;
        int maxlen = 0;
        for(int i = 1; i < len-1; i++)
        {
            if(p[i] > maxlen)
            {
                center = i;
                maxlen = p[i];
            }
        }
        return s.substr((center-1-maxlen)/2,maxlen);
    }
};