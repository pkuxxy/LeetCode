class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(1,0);
        if(n <= 0)
            return ret;
        //ret.push_back(1);
        for(int i = 1; i <= n; i++)
        {
            int cur = 1<<(i-1);
            for(int j = ret.size()-1; j >= 0; j--)
            {
                ret.push_back(ret[j] + cur);
            }
        }
    }
};