class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len = s.size();
        if(!len || nRows <= 0)
            return "";
        if(nRows == 1 || nRows >= len)
            return s;
        stringstream ss;
        int dis = 2*(nRows-1);
        for(int i = 0; i < nRows; i++)
        {
            int interval = 2*(nRows - i-1);
            for(int j = i; j < len; j += dis)
            {
                ss<<s[j];
                if(i != 0 && i!=nRows-1 && j+interval < len)
                    ss<<s[j+interval];
            }
        }
        return ss.str();
    }
};