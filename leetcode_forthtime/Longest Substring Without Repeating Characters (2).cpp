class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        vector<int> pos(26,-1);
        int begin = 0;
        int maxlen = 0;
        for(int i = 0; i < len; i++)
        {
            if(pos[s[i] - 'a'] != -1)
            {
                maxlen = max(maxlen, i-begin);
                int end = pos[s[i]-'a'];
                for(int j = begin; j <= end; j++)
                {
                    pos[s[j] - 'a'] = -1;
                }
                begin = end+1;
            }
            pos[s[i]-'a'] = i;
        }
        maxlen = max(maxlen, len-begin);
        return maxlen;
    }
};