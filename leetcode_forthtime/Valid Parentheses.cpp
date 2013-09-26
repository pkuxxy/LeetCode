class Solution {
public:
    bool match(char c1, char c2)
    {
        return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') ||(c1 == '[' && c2 == ']');
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(!len)
            return true;
        stack<char> st;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.empty() || !match(st.top(), s[i]))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};