// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;
int minWindow(string s, string t)
{
    int lens = s.size();
    int lent = t.size();
    int needToFind[256] = {0};
    int hasFound[256] = {0};
    for(int i = 0; i < lent; i++)
    {
        needToFind[t[i]]++;
    }
    int begin = 0;
    int count = 0;
    int minlen = INT_MAX;
    for(int i = 0; i < lens; i++)
    {
        if(needToFind[s[i]] == 0)
            continue;
        hasFound[s[i]]++;
        if(hasFound[s[i]] <= needToFind[s[i]])
            count++;
        if(count == lent)
        {
            while(needToFind[s[begin]] == 0 || hasFound[s[begin]] > needToFind[s[begin]])
            {
                if(hasFound[s[begin]] > needToFind[s[begin]])
                    hasFound[s[begin]]--;
                begin++;
            }
            minlen = min(minlen, i-begin+1);
            
        }
    }
    return minlen;
}
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s,t)<<endl;
    getchar();
    return 0;
}