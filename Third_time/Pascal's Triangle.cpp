class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(numRows <= 0)
            return ret;
        vector<int> cur;
        cur.push_back(1);
        while(numRows--)
        {
            ret.push_back(cur);
            vector<int> next;
            next.push_back(1);
            for(int i = 1; i < cur.size(); i++)
            {
                next.push_back(cur[i-1] + cur[i]);
            }
            next.push_back(1);
            cur = next;
        }
        return ret;
    }
};