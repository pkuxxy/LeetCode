class Solution {
public:
    bool match(char a, char b)
    {
        if(a == '(')
            return b == ')';
        else if(a == '[')
            return b == ']';
        else if(a == '{')
            return b == '}';
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        for(int i = 0 ;i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if(st.empty() || !match(st.top(), s[i]))
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};