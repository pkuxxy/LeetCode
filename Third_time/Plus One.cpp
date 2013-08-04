class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(!digits.size())
            return ret;
        int carry = 1;
        int len = digits.size();
        for(int i = len-1; i >= 0; i--)
        {
            int tmp = digits[i] + carry;
            ret.push_back(tmp%10);
            carry = tmp/10;
        }
        if(carry)
        ret.push_back(1);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};