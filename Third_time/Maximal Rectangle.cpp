class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = matrix.size();
        if(!len1)
            return 0;
        int len2 = matrix[0].size();
        vector<int> h(len2, 0);
        vector<int> l(len2, 0);
        vector<int> r(len2, len2);
        int ret = 0;
        for(int i = 0; i < len1; i++)
        {
            int left = 0;
            for(int j = 0; j < len2; j++)
            {
                l[j] = max(left, l[j]);
                if(matrix[i][j] == '1')
                {
                    h[j]++;
                }
                else
                {
                    h[j] = 0;
                    l[j] = 0;
                    //r[j] = len2;
                    left = j+1;
                }
            }
            int right = len2;
            for(int j = len2-1; j >= 0; j--)
            {
                r[j] = min(right, r[j]);
                if(matrix[i][j] == '0')
                {
                    r[j] = len2;
                    right = j;
                }
                else
                    ret = max(ret, h[j] * (r[j]-l[j]));
            }
        }
        return ret;
    }
};