class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = S.size();
        int len2 = T.size();
        vector<int> needFound(256, 0);
        vector<int> hasFound(256, 0);
        for(int i = 0; i < len2; i++)
        {
            needFound[T[i]]++;
        }
        string ret;
        int begin = 0;
        int count = 0;
        int minlen = INT_MAX;
        for(int i = 0; i < len1; i++)
        {
            if(needFound[S[i]] == 0)
                continue;
            hasFound[S[i]]++;
            if(hasFound[S[i]] <= needFound[S[i]])
                count++;
            if(count == len2)
            {
                while(needFound[S[begin]] == 0 || hasFound[S[begin]] > needFound[S[begin]])
                {
    				//cout<<hasFound[S[begin]]<<" "<<needFound[S[begin]]<<endl;
                    if(hasFound[S[begin]] > needFound[S[begin]])
                        hasFound[S[begin]]--;
                    begin++;
                }
                int curlen = i-begin+1;
                if(curlen < minlen)
                {
                    minlen = curlen;
                    ret = S.substr(begin, curlen);
                }
            }
        }
        return ret;
    }
};