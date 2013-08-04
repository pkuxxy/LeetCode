class Solution {
public:
    string trim(string& s)
    {
        if(s.empty())
            return s;
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        return s;
    }
    bool isNum(char c)
    {
        return c >= '0' && c <= '9';
    }
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s)
            return false;
        string ts(s);
        trim(ts);
        bool hasE = false;
        bool hasNum = false;
        bool hasDot = false;
        for(int i = 0; i < ts.size(); i++)
        {
            if(!isNum(ts[i]) && ts[i] != '+' && ts [i] != '-' && ts[i] != 'e' && ts[i] != '.')
                return false;
            if(ts[i] == '+' || ts[i] == '-')
            {
                if((i != 0 && ts[i-1] != 'e') || i == ts.size()-1)
                    return false;
            }
            else if(ts[i] == 'e')
            {
                if(hasE || !hasNum || i == ts.size()-1)
                    return false;
                else
                    hasE = true;
            }
            else if(ts[i] == '.')
            {
                if(hasDot || hasE)
                    return false;
                else
                    hasDot = true;
            }
            else
                hasNum = true;
        }
        return hasNum;
    }
};