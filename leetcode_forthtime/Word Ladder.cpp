class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
    	// DO NOT write int main() function
		int len = start.size();
		if(!len || len != end.size())
			return 0;
		map<string, string> m;
		queue<string> q;
		q.push(start);
		m[start] = "";
        int minl = INT_MAX;
        int count = 0;
		while(!q.empty())
		{
			string cur = q.front();
			q.pop();
			for(int i = 0; i < len; i++)
			{
				string tmp = cur;
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					if(cur[i] == ch)
						continue;
					tmp[i] = ch;
					if(tmp == end)
					{
                        count = 2;
						map<string, string>::iterator iter = m.find(cur);
						while(iter->second != "")
						{
                            count++;
							iter = m.find(iter->second);
						}
                        return count;
					}
					else if(dict.find(tmp) != dict.end() && m.find(tmp) == m.end())
					{
						q.push(tmp);
						m[tmp] = cur;
					}
				}
			}
		}
		return count;
    }
};