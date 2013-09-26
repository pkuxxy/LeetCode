class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s,t;
        int maxa = 0;
        int len = height.size();
        vector<int> width(len);
        for(int i = 0; i < len ;i++)
        {
            while(!s.empty() && height[s.top()] >= height[i])
                s.pop();
            width[i] = s.empty()?(i+1):(i-s.top());
            s.push(i);
        }
        for(int i = len-1; i >= 0; i--)
        {
            while(!t.empty() && height[t.top()] >= height[i])
                t.pop();
            width[i] += t.empty()?(len-i-1):(t.top()-i-1);
            t.push(i);
        }
        for(int i = 0; i < len; i++)
        {
            maxa = max(maxa, height[i] * width[i]);
        }
        return maxa;
    }
};