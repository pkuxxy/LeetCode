class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = digits.size();
        if(!len)
            return digits;
        digits[len-1] += 1;
        for(int i = len-1; i >= 1; i--)
        {
            digits[i-1] += digits[i]/10;
            digits[i] %= 10;
        }
        if(digits[0] >= 10)
        {
            digits[0] -= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
            
    }
};