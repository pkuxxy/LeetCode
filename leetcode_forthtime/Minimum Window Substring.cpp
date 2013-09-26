class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lens = S.size();
        int lent = T.size();
        vector<int> needFind(256, 0);
        vector<int> hasFound(256, 0);
        for(int i = 0; i < lent; i++)
        {
            needFind[T[i]]++;
        }
        int minw = INT_MAX;
        string ret;
        int begin = 0;
        for(int i = 0; i < lens; i++)
        {
            if(needFind[S[i]] == 0)
                continue;
            hasFound[S[i]]++;
            if(hasFound[S[i]] <= needFind[S[i]])
                    lent--;
            if(lent == 0)
            {
                while(needFind[S[begin]] == 0 || hasFound[S[begin]] > needFind[S[begin]])
                {
                    if(hasFound[S[begin]] > needFind[S[begin]])
                        hasFound[S[begin]]--;
                    begin++;
                }
                int curlen = i-begin+1;
                if(curlen < minw)
                {
                    minw = curlen;
                    ret = S.substr(begin, minw);
                }
            }
        }
        return ret;
    }
};