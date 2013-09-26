class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if(len < 3)
            return INT_MAX;
        sort(num.begin(), num.end());
        int closest = INT_MAX;
        int mind = INT_MAX;
        for(int i = 0; i < len; i++)
        {
            if(i != 0 && num[i] == num[i-1])
                continue;
            for(int j = i+1, k = len-1; j < k;)
            {
                if(j != i+1 && num[j] == num[j-1])
                {
                    j++;
                    continue;
                }
                if(k != len-1 && num[k] == num[k+1])
                {
                    k--;
                    continue;
                }
                int sum = num[i] + num[j] + num[k];
                int diff = abs(sum - target);
                if(diff == 0)
                {
                    return target;
                }
                if(diff < mind)
                {
                    mind = diff;
                    closest = sum;
                }
                if(sum < target)
                    j++;
                else
                    k--;
            }
        }
        return closest;
    }
};