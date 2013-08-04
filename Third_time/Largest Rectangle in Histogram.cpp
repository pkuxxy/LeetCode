class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if(!len)
            return 0;
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        stack<pair<int, int>> st;
        st.push(make_pair(-1,-1));
        for(int i = 0; i < len ;i++)
        {
            pair<int, int> cur = st.top();
            while(height[i] <= cur.first)
            {
                st.pop();
                cur = st.top();
            }
            st.push(make_pair(height[i],i));
            left[i] = i-cur.second-1;
        }
        st = stack<pair<int, int>>();
        st.push(make_pair(-1,len));
        for(int i = len-1; i >= 0; i--)
        {
            pair<int ,int> cur = st.top();
            while(height[i] <= cur.first)
            {
                st.pop();
                cur = st.top();
            }
            st.push(make_pair(height[i],i));
            right[i] = cur.second-i-1;
        }
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            sum = max(sum, height[i]*(left[i]+right[i]+1));
        }
        return sum;
    }
};