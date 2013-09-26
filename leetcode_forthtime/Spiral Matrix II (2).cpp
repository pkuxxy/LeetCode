class Solution {
public:
    
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1)
            return vector<vector<int>>();
        vector<vector<int>> ret(n, vector<int>(n));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int x = 0;
        int y = -1;
        int num = 1;
        int dir = 0;
        while(n > 0)
        {
            int count = n;
            while(count--)
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