class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1, 0};
        if(n <= 0)
            return vector<vector<int>>();
        vector<vector<int>> ret(n, vector<int>(n));
        int x = 0;
        int y = -1;
        int dir = 0;
        int num = 1;
        while(n)
        {
            for(int i = 0; i < n; i++)
            {
                x += dx[dir];
                y += dy[dir];
                ret[x][y] = num++;
            }
            if(dir%2 == 0)
                n--;
            dir = (dir+1)%4;
        }
        return ret;
    }
};