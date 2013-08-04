class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(rowIndex < 0)
            return ret;
        ret.resize(rowIndex+1);
        ret[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
        {
            ret[i] = 1;
            for(int j = i-1; j >= 1;j--)
                ret[j] += ret[j-1];
        }
        return ret;
    }
};