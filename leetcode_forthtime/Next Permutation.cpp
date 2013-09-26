class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        int i = len-2;
        for(; i >= 0; i--)
        {
            if(num[i] < num[i+1])
                break;
        }
        if(i < 0)
        {
           reverse(num.begin(),num.end());
           return;
        }
            
        int j = len-1;
        for(; j >= 0; j--)
        {
            if(num[j] > num[i])
                break;
        }
        swap(num[i],num[j]);
        reverse(num.begin()+i+1, num.end());
    }
};