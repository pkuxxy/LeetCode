class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return "";
        string pre = "1";
        n--;
        while(n--)
        {
            int count = 1;
            stringstream cur;
            for(int i = 1; i < pre.size(); i++)
            {
                if(pre[i] == pre[i-1])
                    count++;
                else
                {
                    cur<<count<<pre[i-1];
                    count = 1;
                }
            }
            cur<<count<<pre[pre.size()-1];
            pre = cur.str();
        }
        return pre;
    }
};