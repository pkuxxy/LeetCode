class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        int len = strs.size();
        if(!len)
            return ret;
        map<string, vector<string>> vm;
        for(int i = 0; i < len; i++)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            map<string, vector<string>>::iterator iter = vm.find(cur);
            if(iter == vm.end())
            {
                vector<string> list;
                list.push_back(strs[i]);
                vm[cur] = list;
            }
            else
            {
                iter->second.push_back(strs[i]);
            }
        }
        map<string, vector<string>>::iterator iter = vm.begin();
        for(; iter != vm.end(); iter++)
        {
            if(iter->second.size() > 1)
            {
                for(int i = 0; i < iter->second.size(); i++)
                {
                    ret.push_back(iter->second[i]);
                }
            }
        }
        return ret;
    }
};