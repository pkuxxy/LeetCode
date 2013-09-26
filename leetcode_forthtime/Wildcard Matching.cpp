class Solution {
public:
    bool initCheck(const char* s, const char* p)
	{
		int lens = strlen(s);
		int count = 0;
		for(; *p; p++)
		{
			if(*p != '*')
				count++;
		}
		return lens >= count;
	}
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s || !p || !initCheck(s, p))
			return false;
		if(!*p)
			return !*s;
		int len = strlen(p);
		vector<bool> pre(len, false);
		vector<bool> cur(len, false);
		bool isFirst = true;
		for(int i = 0; i < len; i++)
		{
			if(p[i] == '*')
				pre[i] = (i == 0) || pre[i-1];
			else if((*s == p[i] || p[i] == '?') && isFirst)
			{
				isFirst = false;
				pre[i] = true;
			}
			else
				break;
		}
		s++;
		while(*s)
		{
			for(int i = 0; i < len; i++)
			{
				if(p[i] == '*')
				{
					cur[i] = pre[i] || (i != 0 && cur[i-1]);
				}
				else
				{
					cur[i] = (i != 0 && pre[i-1] && (p[i] == *s || p[i] == '?')); 
				}
			}
			pre.assign(cur.begin(), cur.end());
			cur.assign(len, false);
			s++;
		}
		return pre[len-1];
    }
};