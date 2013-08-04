class Node
{
public:
    char c;
    int index;
    Node(char cc, int i)
    {
        c = cc;
        index = i;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return 0;
        stack<Node> st;
        st.push(Node(')',-1));
        int maxlen = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                st.push(Node(s[i], i));
            }
            else
            {
                if(st.top().c == ')')
                {
                    st.push(Node(s[i], i));
                }
                else
                {
                    st.pop();
                    maxlen = max(maxlen, i - st.top().index);
                }
            }
        }
        return maxlen;
    }
};