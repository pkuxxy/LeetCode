class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return "";
        string s = "1";
        n--;
        while(n--)
        {
            string cur;
            int start = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(i != s.size()-1 && s[i] == s[i+1])
                    continue;
                else
                {
                    cur.push_back(i-start+1+'0');
                    cur.push_back(s[i]);
                    start = i+1;
                }
            }
            s = cur;
        }
        return s;
    }
};