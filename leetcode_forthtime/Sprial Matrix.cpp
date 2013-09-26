class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        vector<int> ret;
        int len1 = matrix.size();
        if(!len1)
            return ret;
        int len2 = matrix[0].size();
        int x = 0;
        int y = -1;
        int dir = 0;
        while(len1 > 0 && len2 > 0)
        {
            int count = dir%2 ? len1:len2;
            for(int i = 0; i < count; i++)
            {
                x += dx[dir];
                y += dy[dir];
                ret.push_back(matrix[x][y]);
            }
            dir%2 ? (len2--):(len1--);
            dir = (dir+1)%4;
        }
        return ret;
    }
};