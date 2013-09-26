class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string::iterator i = a.begin();
        string::iterator j = b.begin();
        stringstream ss;
        int carry = 0;
        while(i!= a.end() || j != b.end())
        {
            int sum = carry;
            if(i != a.end())
                sum += *(i++)-'0';
            if(j != b.end())
                sum += *(j++)-'0';
            carry = sum/2;
            ss<<(sum%2);
        }
        if(carry)
            ss<<1;
        string ret = ss.str();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};