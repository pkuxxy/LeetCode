class Solution {
public:
    bool isNum(char c)
    {
        return c >= '0' && c <= '9';
    }
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(str && *str == ' ')
            str++;
        if(!str)
            return 0;
        if(*str != '+' && *str != '-' && !isNum(*str))
            return false;
        bool sign = true;
        if(*str == '+' || *str == '-')
        {
            sign = *str == '+'?true:false;
            str++;
        }
        int ret = 0;
        while(str && isNum(*str))
        {
            int digit = *str - '0';
            if((INT_MAX-digit)/10 >= ret)
                ret = ret * 10 + digit;
            else
                return sign?INT_MAX:INT_MIN;
            str++;
        }
        return sign ? ret:-ret;
    }
};