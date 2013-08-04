class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(nRows <= 1 || nRows >= len)
            return s;
        int zig = 2*nRows-3;
        string ret;
        for(int i = 0; i < nRows; i++)
        {
            int index = i;
            int cur = zig - 2*i;
            while(index < s.size())
            {
                ret.push_back(s[index]);
				index++;
				if(cur != zig && cur > 0 && index+cur < s.size())
                {
                    ret.push_back(s[index+cur]);
                }
                index += zig;
            }
        }
        return ret;
    }
};