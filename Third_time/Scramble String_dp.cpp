class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s1.size();
		//cout<<(s1.size() == s2.size())<<endl;
		if(len != s2.size())
            return false;
        vector<vector<vector<bool>>> f(len+1, vector<vector<bool>>(len,vector<bool>(len, false)));
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
                f[1][i][j] = (s1[i] == s2[j]);
        }
        for(int l = 2; l <= len; l++)
        {
            for(int i = 0; i < len-l+1; i++)
            {
                for(int j = 0; j < len-l+1; j++)
                {
                    for(int k = 1; k < l; k++)
                    {
                        if((f[k][i][j] && f[l-k][i+k][j+k]) || (f[k][i][j+l-k]&&f[l-k][i+k][j]))
                        {
                            f[l][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[len][0][0];
    }
};