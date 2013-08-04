class Solution {
public:
    static map<char, int> m;
    static void init()
	{
		m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
	}
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		init();
        int ret = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i != s.size()-1 && m[s[i]] < m[s[i+1]])
                ret -= m[s[i]];
            else
                ret += m[s[i]];
        }
        return ret;
    }
};
map<char, int> Solution::m;