class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        vector<int> pos(256, -1);
        int begin = 0;
        int maxl = 0;
        for(int i = 0; i < len; i++)
        {
            if(pos[s[i]] != -1)
            {
                maxl = max(maxl, i-begin);
                for(int j = begin; j < pos[s[i]]; j++)
                {
                    pos[s[j]] = -1;
                }
                begin = pos[s[i]]+1;
            }
            pos[s[i]] = i;
        }
        maxl = max(maxl, len-begin);
        return maxl;
    }
};