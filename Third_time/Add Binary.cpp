class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(true)
        {
            if(i >= 0)
            {
                carry += a[i] - '0';
                i--;
            }
            if(j >= 0)
            {
                carry += b[j] - '0';
                j--;
            }
            ret.push_back((carry%2)+'0');
            carry /= 2;
            if(i < 0 && j < 0)
            break;
        }
        if(carry)
        ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};