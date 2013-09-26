class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(1,0);
        for(int i = 0; i < n; i++)
        {
            int cur = 1<<i;
            for(int j = ret.size()-1; j >= 0;j--)
            {
                ret.push_back(ret[j]+cur);
            }
        }
        return ret;
    }
};