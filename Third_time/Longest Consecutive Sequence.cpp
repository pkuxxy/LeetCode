class Solution {
public:
    int getlen(map<int, bool>& vm, int n, bool asc)
    {
        int count = 0;
        map<int, bool>::iterator iter = vm.find(n);
        while(iter != vm.end())
        {
            count++;
            n = asc?(n+1):(n-1);
            vm.erase(iter);
            iter = vm.find(n);
        }
        return count;
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if(!len)
            return 0;
        map<int, bool> vm;
        for(int i = 0; i < len; i++)
        {
            vm.insert(pair<int, bool>(num[i], true));
        }
        int maxl = 0;
        for(int i = 0; i < len; i++)
        {
            map<int, bool>::iterator iter = vm.find(num[i]);
            if(iter == vm.end())
                continue;
            int cur = 1 + getlen(vm, iter->first-1, false) + getlen(vm ,iter->first+1, true);
            maxl = max(maxl, cur);
        }
        return maxl;
    }
};