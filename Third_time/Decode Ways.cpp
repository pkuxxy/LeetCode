class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return 0;
        vector<int> ret(len+1,0);
        ret[0] = 1;
        ret[1] = s[0] != '0'?1:0;
        for(int i = 1; i < len; i++)
        {
            if(s[i-1] >= '3')
            {
                if(s[i] == '0')
                    ret[i+1] = 0;
                else
                    ret[i+1] = ret[i];
            }
                
            else if(s[i-1] == '2')
            {
                if(s[i] > '6')
                    ret[i+1] = ret[i];
                else if(s[i] == '0')
                    ret[i+1] = ret[i-1];
                else
                    ret[i+1] = ret[i] + ret[i-1];
            }
            else if(s[i-1] == '1')
            {
                if(s[i] == '0')
                    ret[i+1] = ret[i-1];
                else
                    ret[i+1] = ret[i] + ret[i-1];
            }
            else if(s[i-1] == '0')
            {
                if(s[i] == '0')
                    ret[i+1] = 0;
                else
                    ret[i+1] = ret[i];
            }
                
        }
        return ret[len];
        
    }
};