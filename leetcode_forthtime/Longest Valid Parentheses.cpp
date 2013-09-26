class Solution {
public:
    int longestValidParentheses(string s) {
		int stack = 0;
        int continues = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            continues++;
            stack = (s[i] == '(')?stack+1:stack-1;
            if(stack == 0)
            {
                result = max(result, continues);
            }
            else if(stack < 0)
            {
                continues = 0;
                stack = 0;
            }
        }
        
        continues = 0;
        stack = 0;
        for(int i = s.size(); i >= 0; i--)
        {
            continues ++;
            stack = (s[i] == ')')?stack+1:stack-1;
            if(stack == 0)
            {
                result = max(result, continues);
            }
            else if(stack < 0)
            {
                stack = 0;
                continues = 0;
            }
        }
        return result;
	}
};