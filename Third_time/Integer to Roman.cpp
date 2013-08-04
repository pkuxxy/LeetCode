class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        char *sym[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ret;
        for(int i = 0; i < 13; i++)
        {
            int count = num/nums[i];
            num -= count*nums[i];
            while(count--)
                ret.append(sym[i]);
        }
        return ret;
    }
};