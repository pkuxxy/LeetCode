class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int start = 0;
        vector<int> map(256, -1);
        int i = 0;
        for(; i < s.size(); i++)
        {
            if(map[s[i]] != -1)
            {
                ret = max(ret, i - start);
                for(int j = start; j < map[s[i]];j++)
                    map[s[j]] = -1;
                start = map[s[i]]+1;
            }
            map[s[i]] = i;
        }
        ret = max(ret, i-start);
        return ret;
    }
};