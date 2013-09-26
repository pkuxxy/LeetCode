class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = S.size();
        vector<int> ret;
        map<string, int> toFind;
        map<string, int> hasFind;
        int N = L.size();
        int M = L[0].size();
        for(int i = 0; i < N; i++)
        {
            toFind[L[i]]++;
        }
        for(int i = 0,j; i <= len-N*M; i++)
        {
            hasFind.clear();
            for(j = 0; j < N; j++)
            {
                int k = i+j*M;
                string sub = S.substr(k, M);
                if(toFind.find(sub) == toFind.end())
                    break;
                hasFind[sub]++;
                if(hasFind[sub] > toFind[sub])
                    break;
            }
            if(j == N)
                ret.push_back(i);
        }
        return ret;
    }
};