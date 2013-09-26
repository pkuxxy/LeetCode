class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> num3(len1+len2, 0);
        for(int i = len1-1; i >= 0; i--)
        {
            int carry = 0;
            for(int j = len2-1; j >= 0; j--)
            {
                num3[i+j+1] += (num1[i]-'0')*(num2[j]-'0')+carry;
                carry = num3[i+j+1]/10;
                num3[i+j+1] %= 10;
            }
            num3[i] = carry;
        }
        int i = 0;
        while(i < len1+len2-1 && num3[i] == 0)
            i++;
        string ret;
        for(; i < len1+len2; i++)
        {
            ret.push_back(num3[i]+'0');
        }
        return ret;
    }
};