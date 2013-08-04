class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = words.size();
        vector<string> ret;
        int begin = 0;
        int len = 0;
        for(int i = 0; i < n ;i++)
        {
            if(len + words[i].size() + (i-begin) > L)
            {
                ret.push_back(connect(words, begin, i-1, len, L, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        ret.push_back(connect(words, begin, n-1, len,L, true));
        return ret;
    }
    string connect(vector<string> &words, int s, int e, int len, int L, bool left)
    {
        string ret;
        int n = e-s+1;
        for(int i = 0; i < n; i++)
        {
            ret.append(words[s+i]);
            addspace(ret, i, n-1,L-len, left);
        }
        if(ret.size() < L)
            ret.append(L-ret.size(), ' ');
		return ret;
    }
    void addspace(string& s, int i, int n, int sc, bool left)
    {
		if(n<1 || i > n-1)
			return;
        int space = left?1:(sc/n+(i<(sc%n)?1:0));
        s.append(space,' ');
    }
};