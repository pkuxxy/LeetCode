class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        int maxa = 0;
        int i = 0;
        int j = len-1;
        while(i < j)
        {
            int minh = min(height[i], height[j]);
            maxa = max(maxa, minh*(j-i));
            while(i < j && minh >= height[i])
                i++;
            while(i < j && minh >= height[j])
                j--;
        }
        return maxa;
    }
};