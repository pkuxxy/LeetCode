class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if(!len)
            return;
        int i = len-2;
        while(i >= 0 && num[i] >= num[i+1])
        {
            i--;
        }
        if(i < 0)
            reverse(num.begin(), num.end());
        else
        {
            int j = len-1;
            while(num[j] <= num[i])
                j--;
            swap(num[i],num[j]);
            reverse(num.begin()+i+1, num.end());
        }
    }
};