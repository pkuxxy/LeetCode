class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if(len < 2)
            return 0;
        int ret = 0;
        int minh = 0;
        int i = 0;
        int j = len-1;
        while(i < j)
        {
            minh = min(height[i],height[j]);
            ret = max(ret, (j-i)*minh);
            if(height[i] < height[j])
            {
                i++;
                while(i<j && height[i] <= minh)
                    i++;
            }
            else
            {
                j--;
                while(i<j && height[j] <= minh)
                    j--;
            }
        }
        return ret;
    }
};