class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> st;
        int len = path.size();
        string cur;
        for(int i = 0; i <= len; i++)
        {
            if(i == len || path[i] == '/')
            {
                if(cur.size())
                {
                    if(cur == "..")
                    {
                        if(!st.empty())
                            st.pop_back();
                    }
                    else if(!(cur == "."))
                        st.push_back(cur);
                    cur.clear();
                }
            }
            else
            {
                cur.push_back(path[i]);
            }
        }
        string ret;
        for(int i = 0; i < st.size(); i++)
        {
            ret.push_back('/');
            ret.append(st[i]);
        }
        return ret.size()?ret:"/";
    }
};