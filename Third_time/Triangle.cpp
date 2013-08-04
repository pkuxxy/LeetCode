class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = triangle.size();
        if(!len1)
            return 0;
        vector<int> ret(len1,0);
        ret[0] = triangle[0][0];
        for(int i = 1; i < len1; i++)
        {
            for(int j = i; j >=0; j--)
            {
                if(j == i)
                    ret[j] = ret[j-1] + triangle[i][j];
                else if(j == 0)
                    ret[j] += triangle[i][j];
                else
                    ret[j] = min(ret[j],ret[j-1]) + triangle[i][j];
            }
        }
		int mins = INT_MAX;
        for(int i = 0; i < len1; i++)
		{
			mins = min(mins,ret[i]);
		}
		return mins;
    }
};